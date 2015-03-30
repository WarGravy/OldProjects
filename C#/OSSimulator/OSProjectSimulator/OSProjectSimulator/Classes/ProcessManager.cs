using System;
using System.IO;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading;
using System.Text.RegularExpressions;
using System.Diagnostics;

namespace OSProjectSimulator.Classes
{
    class ProcessManager
    {
        public int Quantum { get; set; }
        public int ProcessorCycleTime { get; set; }
        public Process Run { get; set; }
        public ProcessQueue Ready { get; set; }
        public List<Process> Waiting { get; set; }
        private Stopwatch stopwatch;
        
        public ProcessManager(Configuration config)
        {
            // Create Run
            Run = null;
            // Create Ready Queue
            if (config.ProcessorScheduling == "SJF")
            {
                Ready = new SJF();
            }
            else
            {
                Ready = new FCFS();
            }
            // Create Waiting
            Waiting = new List<Process>();
            // Get Quantum
            Quantum = config.Quantum;
            // Get Cycle Time
            ProcessorCycleTime = config.ProcessorCycleTime;

            // Initialize stopwatch
            stopwatch = new Stopwatch();

            // Open MetaData
            String file;
            using (StreamReader sr = new StreamReader(config.FilePath))
            {
                file = sr.ReadToEnd();
            }
            // Clip System Start
            string[] stringSeparators = new string[] { "S(start)0;", "A(start)0;", "S(end)0.", "A(end)0;" };
            file = file.Replace(" ", "").Replace(Environment.NewLine, "").Replace("ProgramMeta-DataCode:", "");
            string[] lines = file.Split(stringSeparators, StringSplitOptions.RemoveEmptyEntries);

            int initPID = 1;
            // While not at System End
            foreach (string line in lines)
            {
                Logger.Instance.write("PID: " + initPID + " Entering System");
                stopwatch.Start();
                // Create Process using String in Ready
                Ready.Add(new Process(line, initPID));
                stopwatch.Stop();
                decimal ms = (stopwatch.ElapsedTicks * 1000) / (decimal)Stopwatch.Frequency;
                Logger.Instance.write("SYSTEM: Creating PID " + initPID + " (" + ms.ToString("F") + " milliseconds)");
                initPID++;
            }
            if (Ready.Count() > 0)
            {
                Run = Ready.Remove();
            }
        }

        public Interrupt Cycle()
        {
            Interrupt result = null;

            if (Run != null)
            {
                // Simulate Running Time For Process Operation
                if (Run.Data.Count > 0 && Run.Data[0].component == componentType.Process)
                {
                    int processTime = ProcessorCycleTime * Math.Min(Quantum, Run.Data[0].numCycles);
                    Logger.Instance.write("PID: " + Run.PID + " Processing for (" + processTime + " milliseconds)");
                    Thread.Sleep(processTime);
                }
                ///while we still have processes
                for (int i = 0; i < Quantum; i++)
                {
                    //cycle the process
                    result = Run.Cycle();
                    //check for interrupt
                    if (result != null)
                    {
                        //IF interrupt, create interrupt, place into wait, return interrupt
                        RunToWait();
                        return result;
                    }
                    //if a processing operation has completed
                    if (Run.Data.Count > 0 && Run.Data[0].numCycles == 0)
                    {
                        Run.Data.RemoveAt(0);
                        break;
                    }
                    //process has completely finished, remove from system
                    if (Run.Data.Count() <= 0)
                    {
                        Logger.Instance.write("PID: " + Run.PID + " Exiting System");
                        break;
                    }
                }
                //end for loop
                RunToReady();
            }
            else
            {
                ReadyToRun();
            }

            return result;
        }

        public void RunToReady()
        {
            //if process is not done
            if (Run.Data.Count > 0)
            {
                // Move Process from Run to Ready
                Ready.Add(Run);
            }
            ReadyToRun();
        }

        public void RunToWait()
        {
            // Move Process from Run to Wait
            Waiting.Add(Run);
            // Move Process from Ready to Run
            ReadyToRun();
        }

        public void ReadyToRun()
        {
            
            // Move Process from Ready to Run
            if (Ready.Count() > 0) 
            {
                stopwatch.Start();
                Run = Ready.Remove();
                stopwatch.Stop();
                decimal ms = (stopwatch.ElapsedTicks * 1000) / (decimal)Stopwatch.Frequency;
                Logger.Instance.write("SYSTEM: Swapping Processes " + " (" + ms.ToString("F") + " milliseconds)");
            }
            else
            {
                Run = null;
            }
            
        }

        public void WaitToReady(int pid)
        {
            // Move Process from Wait to Ready
            if (Waiting.Where(x => x.PID == pid).ToList().Count() > 0)
            {
                Ready.Add(Waiting.Where(x => x.PID == pid).ToList().First());
            }
            //filter it out of waiting list
            Waiting = Waiting.Where(x => x.PID != pid).ToList();
        }
    }
}
