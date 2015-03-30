using System;
using System.IO;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace OSProjectSimulator.Classes
{
    public class Logger
    {
        private static volatile Logger instance;
        private static object syncRoot = new Object();
        private static object writeLock = new Object();
        private int logOption;
        private string path = "Log.txt";

        // nondefault constructor for initially setting up Logger with config info
        private Logger(Configuration c) 
        {
            switch(c.Log)
            {
                case "LogtoBoth":
                    logOption = 0;
                    break;
                case "LogtoMonitor":
                    logOption = 1;
                    break;
                case "LogtoFile":
                    logOption = 2;
                    break;
                default:
                    logOption = -1;
                    Console.WriteLine("Error: Invalid Log option in config file. Use 'Log to Both', 'Log to Monitor', or 'Log to File'");
                    break;
            }

            if ((logOption == 2 || logOption == 0))
            {
                if (!File.Exists(path))
                {
                    // Create a file to write to. 
                    using (StreamWriter sw = File.CreateText(path))
                    {
                        sw.WriteLine();
                        sw.WriteLine("Log Start");
                        sw.WriteLine(c.ProcessorScheduling.ToString());
                        sw.WriteLine("---");
                    }
                }
                else // In case we want to log to a file multiple times
                {
                    using (StreamWriter sw = File.AppendText(path))
                    {
                        sw.WriteLine();
                        sw.WriteLine("Log Start");
                        sw.WriteLine(c.ProcessorScheduling.ToString());
                        sw.WriteLine("---");
                    }
                }
            }
            Console.WriteLine("Log Start");
            Console.WriteLine(c.ProcessorScheduling.ToString());
            Console.WriteLine("---");
        }
        // default constructor stub
        private Logger() { }

        // initialization function for logger, to be called before any call for an instance of logger
        public static Logger initialize(Configuration c) 
        {
            if (instance == null) 
            {
                lock (syncRoot)
                {
                    if (instance == null)
                        instance = new Logger(c);
                }
            }
            return instance;
        }

        // used to get the instance of singleton logger object
        public static Logger Instance
        {
            get 
            {
                if (instance == null)
                {
                    lock (syncRoot)
                    {
                        if (instance == null)
                            instance = new Logger();
                    }
                }
                return instance;
            }
        }

        public void write(string s)
        {
            if (logOption == 0 || logOption == 1) // Write to console
                Console.WriteLine(s);
            if (logOption == 0 || logOption == 2) // Write to File
            {
                lock (writeLock)
                {
                    using (StreamWriter sw = File.AppendText(path))
                    {
                        sw.WriteLine(s);
                    }
                }

            }
        }
    }
}
