using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using SortingAlgorithms.QuickSort;
using SortingAlgorithms.MergeSort;
/**
 * Sorting Algorithms in C#
 * Written by Zachary Ty Carlson
 * Last Edited: 1/1/15
 */

namespace SortingAlgorithms
{
    class Program
    {
        static void Main(string[] args)
        {
            //Merge Sort Test
            MergeSort.MergeSort.Test();

            //Quick Sort Test
            QuickSort.QuickSort.Test();
            //Pause
            System.Console.ReadLine();
        }
    }
}
