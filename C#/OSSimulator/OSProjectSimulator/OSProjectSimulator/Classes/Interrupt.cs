using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading;

namespace OSProjectSimulator.Classes
{
    public enum Flag : int{ keyboardFinish, hardDriveInputFinish,  hardDriveOutputFinish, monitorFinish,
                            keyboardStart, hardDriveInputStart, hardDriveOutputStart, monitorStart };

    public class Interrupt
    {
        public Flag flag { get; private set; }
        public int PID { get; private set; }
        public int numCycles { get; private set;}
        public Configuration config { get; private set; }

        public Interrupt(Flag f, int p, int n)
        {
            flag = f;
            PID = p;
            numCycles = n;
        }

        // call to start io processing thread
        public void StartThread(Configuration c)
        {
            config = c;
            Thread thread = new Thread(RunIO);
            thread.Start();
        }

        public void RunIO()
        {
            int runTime = numCycles;
            // run this thread for io device cycle time * number of cycles from process
            switch (flag) // switches based on what flag is raised by a given process and sets flag to finished after simulated processing
            {
                case Flag.monitorStart:
                    runTime *= config.MonitorDisplayTime;
                    Thread.Sleep(runTime);
                    Logger.Instance.write("PID: " + PID + " Monitor Output End (" + runTime + " milliseconds)");
                    flag = Flag.monitorFinish;
                    break;
                case Flag.keyboardStart:
                    runTime *= config.KeyboardCycleTime;
                    Thread.Sleep(runTime);
                    Logger.Instance.write("PID: " + PID + " Keyboard Output End (" + runTime + " milliseconds)");
                    flag = Flag.keyboardFinish;
                    break;
                case Flag.hardDriveInputStart:
                    runTime *= config.HardDriveCycleTime;
                    Thread.Sleep(runTime);
                    Logger.Instance.write("PID: " + PID + " Hard Drive Input End (" + runTime + " milliseconds)");
                    flag = Flag.hardDriveInputFinish;
                    break;
                case Flag.hardDriveOutputStart:
                    runTime *= config.HardDriveCycleTime;
                    Thread.Sleep(runTime);
                    Logger.Instance.write("PID: " + PID + " Hard Drive Output End (" + runTime + " milliseconds)");
                    flag = Flag.hardDriveOutputFinish;
                    break;
            }
        }
    }
}
