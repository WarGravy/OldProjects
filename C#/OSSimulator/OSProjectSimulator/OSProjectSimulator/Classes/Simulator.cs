using System;
using System.IO;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading;
using System.Diagnostics;

namespace OSProjectSimulator.Classes
{
    class Simulator
    {
        public Configuration Config { get; set; }
        public List<Interrupt> Traps { get; set; }
        public ProcessManager PManager { get; set; }
        private Stopwatch stopwatch;

        public Simulator(string filename)
        {
            stopwatch = new Stopwatch();
            Config = new Configuration(filename);
            //Error Checking
            if (Config.ErrorFlag != 0)
            {
                Config.OutputError();
            }
            //No Errors with Config file
            else
            {
                String file;
                using (StreamReader sr = new StreamReader(Config.FilePath))
                {
                    file = sr.ReadToEnd();
                }
                Logger.initialize(this.Config);
                PManager = new ProcessManager(this.Config);
                Traps = new List<Interrupt>();
            }

        }
        public bool Simulate()
        {
            //loop while processes exist
            
            while (this.PManager.Run != null || this.PManager.Ready.Count() > 0 || this.PManager.Waiting.Count() > 0)
            {
                if (Traps.Count() > 0 && Traps.Where(t => t.flag <= Flag.monitorFinish).ToList().Count() > 0)
                {
                    List<Interrupt> temp = new List<Interrupt>();
                    //move the processes from waiting to ready
                    foreach (Interrupt i in this.Traps.Where(t => t.flag <= Flag.monitorFinish).ToList())
                    {
                        temp.Add(i);
                        this.PManager.WaitToReady(i.PID);
                    }
                    Traps = Traps.Where(t => !temp.Contains(t)).ToList();
                    
                }
                else 
                {
                    Interrupt temp = this.PManager.Cycle();
                    //there was an intterupt
                    if (temp != null)
                    {
                        stopwatch.Start();
                        //add intterrupt to list
                        this.Traps.Add(temp);
                        temp.StartThread(this.Config);
                        stopwatch.Stop();
                        decimal ms = (stopwatch.ElapsedTicks * 1000) / (decimal)Stopwatch.Frequency;
                        Logger.Instance.write("SYSTEM: Managing I/O " + " (" + ms.ToString("F") + " milliseconds)");
                    }
                }
            }
            Logger.Instance.write("Simulation Finish");
            return true;
        }
    }
}
