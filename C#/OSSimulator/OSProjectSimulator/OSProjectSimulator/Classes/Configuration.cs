using System;
using System.IO;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace OSProjectSimulator.Classes
{
    public class Configuration
    {
        //FLAG
        //0 = no error, > 0 corresponds to the member that encountered the error
        public int ErrorFlag { get; set; }
        public string FilePath { get; set; }

        //Simulator Configuration Members
        public double Version { get; set; }
        public int Quantum { get; set; } 
        public string ProcessorScheduling { get; set; }
        public int ProcessorCycleTime { get; set; }
        public int MonitorDisplayTime { get; set; }// (msec)
        public int HardDriveCycleTime { get; set; }// (msec)
        public int PrinterCycleTime { get; set; }// (msec)
        public int KeyboardCycleTime { get; set; }// (msec)
        public string MemoryType { get; set; }
        public string Log { get; set; }

        public Configuration(string f)
        {
            //set errors to none.
            ErrorFlag = 0;
            ParseFile(f);
            if (ErrorFlag == 0) Validate();
        }
        public void OutputError(){
            Console.BackgroundColor.Equals("Blue");
            Console.ForegroundColor.Equals("White");
            switch (this.ErrorFlag)
            {
                case 1:
                    Console.WriteLine("ABORTING! Incorrect version number.");
                    break;
                case 2:
                    Console.WriteLine("ABORTING! Invalid quantum.");
                    break;
                case 3:
                    Console.WriteLine("ABORTING! Unsupported processor scheduling. Supported scheduling strategies are 'RR', 'FIFO' and 'SJF'.");
                    break;
                case 4:
                    Console.WriteLine("ABORTING! Invalid processor cycle time.");
                    break;
                case 5:
                    Console.WriteLine("ABORTING! Invalid monitor display time.");
                    break;
                case 6:
                    Console.WriteLine("ABORTING! Invalid hard drive cycle time.");
                    break;
                case 7:
                    Console.WriteLine("ABORTING! Invalid printer cycle time.");
                    break;
                case 8:
                    Console.WriteLine("ABORTING! Invalid keyboard cycle time.");
                    break;
                case 9:
                    Console.WriteLine("ABORTING! Unsupported memory type.");
                    break;
                case 10:
                    Console.WriteLine("ABORTING! Unsupported logging.");
                    break;
                case 11:
                    Console.WriteLine("ABORTING! File Path was incorrectly specified in the config file. If your file path has a space in it, please wrap your file path in QUOTATION MARKS.");
                    break;
                default:
                    break;
            }
            
        }
        private void Validate()
        {
            //Filepath
            try
            {
                using (StreamReader sr = new StreamReader(this.FilePath))
                {
                    String file = sr.ReadToEnd();
                }
            }
            catch (Exception e)
            {
                this.ErrorFlag = 11;
                Console.WriteLine("ABORTING! The file could not be read:");
                Console.WriteLine(e.Message);
            }
            //Version
            //Quantum 
            if (ProcessorScheduling != "RR" && ProcessorScheduling != "SRTF")
            {
                Quantum = int.MaxValue;
            }
            //ProcessorScheduling
            if (ProcessorScheduling != "RR" && ProcessorScheduling != "FIFO" && ProcessorScheduling != "SJF") 
            {
                this.ErrorFlag = 3;
            }
            //ProcessorCycleTime
            //MonitorDisplayTime (msec)
            //HardDriveCycleTime(msec)
            //PrinterCycleTime (msec)
            //KeyboardCycleTime (msec)
            //MemoryType
            //Log
        }
        private bool ParseFile(string filename)
        {
            //read file
            try
            {
                using (StreamReader sr = new StreamReader(filename))
                {
                    String file = sr.ReadToEnd();
                    file = file.Replace("\r", "");
                    //grab filepath for programs (handled separately for spaces
                    if (file.ToLower().Contains("file") && file.ToLower().Contains("path"))
                    {
                        //create a list of all of the lines
                        List<String> temp = new List<String>();
                        temp = file.Split('\n').ToList();
                        //look for filepath in that list
                        temp = temp.Where(s => s.ToLower().Contains("file") && s.ToLower().Contains("path")).ToList();
                        if (temp.Count() > 0)
                        {
                            //if filename has a space
                            if (temp[0].ToLower().Contains("\""))
                            {
                                this.FilePath = temp[0].Split('"')[1];
                            }
                            //filename does not have a space
                            else
                            {
                                //remove the first occurence of : instead of all : just in case there is a : in the file path
                                while (temp[0].Contains(':'))
                                {
                                    temp[0] = temp[0].Substring(1);
                                    if (temp[0].StartsWith(":"))
                                    {
                                        temp[0] = temp[0].Substring(1);
                                        break;
                                    }
                                }
                                this.FilePath = temp[0].Replace(" ", "");
                            }
                        }
                        else
                        {
                            this.ErrorFlag = 11;
                        }
                    }
                    //iterate through each line in the file checking for values
                    foreach (string line in file.Replace(" ", "").Split('\n'))
                    {
                        if (line.ToLower().Contains("version"))
                        {
                            this.Version = Convert.ToDouble(line.Split(':')[1]);
                        }
                        else if (line.ToLower().Contains("quantum"))
                        {
                            this.Quantum = Convert.ToInt32(line.Split(':')[1]);
                        }
                        else if (line.ToLower().Contains("processorscheduling"))
                        {
                            this.ProcessorScheduling = line.Split(':')[1];
                        }
                        else if (line.ToLower().Contains("processorcycletime"))
                        {
                            this.ProcessorCycleTime = Convert.ToInt32(line.Split(':')[1]);
                        }
                        else if (line.ToLower().Contains("monitordisplaytime"))
                        {
                            this.MonitorDisplayTime = Convert.ToInt32(line.Split(':')[1]);
                        }
                        else if (line.ToLower().Contains("harddrivecycletime"))
                        {
                            this.HardDriveCycleTime = Convert.ToInt32(line.Split(':')[1]);
                        }
                        else if (line.ToLower().Contains("printercycletime"))
                        {
                            this.PrinterCycleTime = Convert.ToInt32(line.Split(':')[1]);
                        }
                        else if (line.ToLower().Contains("keyboardcycletime"))
                        {
                            this.KeyboardCycleTime = Convert.ToInt32(line.Split(':')[1]);
                        }
                        else if (line.ToLower().Contains("memorytype"))
                        {
                            this.MemoryType = line.Split(':')[1];
                        }
                        else if(line.ToLower().Contains("log"))
                        {
                            this.Log = line.Split(':')[1];
                        }
                    }
                }
            }
            //catch file read error
            catch (Exception e)
            {
                this.ErrorFlag = -1;
                Console.WriteLine("ABORTING! The file could not be read:");
                Console.WriteLine(e.Message);
                return false;
            }
            //return
            return true;
        }

    }
}
