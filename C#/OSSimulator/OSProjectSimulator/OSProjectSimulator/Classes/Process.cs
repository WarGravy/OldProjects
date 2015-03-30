using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.IO;

namespace OSProjectSimulator.Classes
{
    public enum componentType {System, Application, Process, Input, Output};
    public enum descriptorType { end = 1, hardDrive = 2, keyboard = 3, monitor = 4, run = 5, start = 6 };
    
    public class MetaData
    {
        public componentType component { get; set; }
        public descriptorType descriptor { get; set; }
        public int numCycles { get; set; }
    }

    public class Process
    {
        public int PID { get; set; }
        public List<MetaData> Data;
        public int totalCycles { get; set; }

        public Process(string metaInfo, int p) 
        {
            PID = p;
            char[] delimiters = {'(',')',';'}; 
            string[] MetaStrings = metaInfo.Replace(" ", "").Replace("\n", "").Replace("\r", "").Split(delimiters);
            Data = new List<MetaData>();

            //once for each metaData item
            for(int i = 0; i < MetaStrings.Length/3; i++){
                 MetaData temp = new MetaData();
                 // based on imported component data, assign component of MetaData object
                 switch(MetaStrings[i*3])
                 {
                 case "S":
                    Console.WriteLine("Error: Individual Processes should not receive a 'S' type.");
		            temp.component = componentType.System;
	        		break;
         		 case "A":
                    Console.WriteLine("Error: Individual Processes should not receive an 'A' type.");
		 	        temp.component = componentType.Application;
			        break;
		         case "P":
		 	        temp.component = componentType.Process;
			        break;
		         case "I":
		 	        temp.component = componentType.Input;
			        break;
		         case "O":
		 	        temp.component = componentType.Output;
			        break;

                 }
   
                 // based on imported descriptor data, assign descriptor of MetaData object
                 switch(MetaStrings[i*3+1])
                 {
                 case "end":
		            temp.descriptor = descriptorType.end;
			        break;
		         case "harddrive":
		         	temp.descriptor = descriptorType.hardDrive;
			        break;
		         case "keyboard":
		 	        temp.descriptor = descriptorType.keyboard;
			        break;
		         case "monitor":
		 	        temp.descriptor = descriptorType.monitor;
			        break;
		         case "run":
		 	        temp.descriptor = descriptorType.run;
			        break;
		         case "start":
		 	        temp.descriptor = descriptorType.start;
			        break;
                 }

                 // based on imported cycle number data, assign numcycles of MetaData object
                 temp.numCycles = Convert.ToInt32(MetaStrings[i*3+2]);
                 totalCycles += temp.numCycles;
    
                 // add the new object into the list
                 Data.Add(temp);
            }
        }

        public Interrupt Cycle()
        {
            if (this.Data.Count() > 0)
            {
                // If operation is to process
                if (this.Data.First().component == componentType.Process)
                {
                    if (Data[0].numCycles > 0)
                    {
                        Data[0].numCycles--;
                    }
                }
                else // If operation is IO
                {
                    if (this.Data.Count() > 0 && this.Data[0].descriptor >= descriptorType.hardDrive && this.Data[0].descriptor <= descriptorType.monitor)
                    {
                        int numberOfCycles = this.Data[0].numCycles;
                        Interrupt result;
                        /**we set it to zero so that once it gets put back into run,
                         * this else section will execute.
                         * Once it executes this will be removed from the list,
                         * and check if there is another interrupt*/
                        this.Data[0].numCycles = 0;

                        //case by case interrupt
                        switch(this.Data[0].descriptor){
                            case descriptorType.hardDrive:
                                if (this.Data[0].component == componentType.Input)
                                {
                                    Logger.Instance.write("PID: " + PID + " Hard Drive Input Start");
                                    result = new Interrupt(Flag.hardDriveInputStart, this.PID, numberOfCycles);
                                }
                                else
                                {
                                    Logger.Instance.write("PID: " + PID + " Hard Drive Output Start");
                                    result = new Interrupt(Flag.hardDriveOutputStart, this.PID, numberOfCycles);
                                }
                                break;
                            case descriptorType.keyboard:
                                Logger.Instance.write("PID: " + PID + " Keyboard Input Start");
                                result = new Interrupt(Flag.keyboardStart, this.PID, numberOfCycles);
                                break;
                            case descriptorType.monitor:
                                Logger.Instance.write("PID: " + PID + " Monitor Output Start");
                                result = new Interrupt(Flag.monitorStart, this.PID, numberOfCycles);
                                break;
                            default:
                                result = null;
                                break;
                        }
                        Data.RemoveAt(0);
                        return result;
                    }
                }
            }
            return null;
        }
    }

}






