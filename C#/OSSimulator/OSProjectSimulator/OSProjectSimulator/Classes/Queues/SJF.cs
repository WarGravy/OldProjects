using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace OSProjectSimulator.Classes
{
    public class SJF : ProcessQueue
    {
        public SJF()
        {
            myQ = new List<Process>();
            comparer = new ShortestJobFirst();
        }
        public int Count()
        {
            return myQ.Count;
        }
        #region Queue
        public void Add(Process p)
        {
            myQ.Add(p);
            myQ.Sort(comparer);
        }
        public Process Remove()
        {
            Process p = myQ.First();
            myQ.RemoveAt(0);
            return p;
        }

        private List<Process> myQ;
        #endregion
        private ShortestJobFirst comparer;

    }

    public class ShortestJobFirst : IComparer<Process>
    {
        public int Compare(Process x, Process y)
        {
            int result = x.totalCycles.CompareTo(y.totalCycles);

            return result;
        }
    }
}
