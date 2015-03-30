using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using OSProjectSimulator.Classes;

namespace OSProjectSimulator
{
    class Program
    {
        static void Main(string[] args)
        {
            //Grab config filename and create Simulator
            if (args.Count() >= 1 && !String.IsNullOrEmpty(args[0]))
            {
                Simulator sim = new Simulator(args[0]);
                if (sim.Config.ErrorFlag == 0) {
                    //Run Simulation
                    sim.Simulate();
                }
            }
            else
            {
                Console.Write("ABORTING! No arguments passed.");
            }

            Console.ReadLine(); //Pause
        }
    }
}
