using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace OSProjectSimulator.Classes
{
    public interface ProcessQueue
    {
        void Add( Process p );
        Process Remove();
        int Count();
    }
}
