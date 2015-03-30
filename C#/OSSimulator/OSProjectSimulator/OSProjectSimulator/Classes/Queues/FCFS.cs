using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace OSProjectSimulator.Classes
{
    class FCFS : ProcessQueue
    {
        public FCFS()
        {
            myQ = new Queue<Process>();
        }
        public int Count()
        {
            return myQ.Count;
        }

        #region Queue
        public void Add( Process p )
        {
            myQ.Enqueue(p);
        }
        public Process Remove()
        {
            return myQ.Dequeue();
        }

        private Queue<Process> myQ;
        #endregion

    }
}
