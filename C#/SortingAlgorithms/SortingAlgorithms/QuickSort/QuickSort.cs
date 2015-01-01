using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
/**
 * Not Stable
 * No Extra Space used
 * Θ(n·lg(n)) time
 * Worst Case O(n^2)
 */
/**
 * This code was influenced from:
 * http://en.wikipedia.org/wiki/Quicksort#Algorithm
 */
namespace SortingAlgorithms.QuickSort
{
    class QuickSort
    {
        public static void Sort<T>(T[] array) where T : IComparable<T>
        {
            if (array != null && array.Length > 1)
            {
                Random rand = new Random();
                Sort(array, 0, array.Length - 1);
            }
        }
        private static void Sort<T>(T[] array, int low, int high) where T : IComparable<T>
        {
            if (low <= high)
            {
                int p = Partition(array, low, high);
                //recursively sort the partitioned pieces
                Sort(array, low, p - 1);
                Sort(array, p + 1, high);
            }
        }
        private static int Partition<T>(T[] array, int low, int high) where T : IComparable<T>
        {
            int pivot = high;
            int wall = low;

            for (int i = low; i < high; i++)
            {
                if ((array[i].CompareTo(array[pivot]) <= 0))
                {
                    //swap the element next to the wall with element at i, increment wall
                    Swap(array, i, wall);
                    wall++;
                }
            }
            //move the pivot
            Swap(array, pivot, wall);

            return wall;
        }
        private static void Swap<T>(T[] array, int i, int j) where T : IComparable<T>
        {
            if (i != j)
            {
                T temp = array[i];
                array[i] = array[j];
                array[j] = temp;
            }
        }
        public static void Test()
        {
            int[] reversed = new[] { 9, 8, 7, 6, 5, 4, 3, 2, 1 };
            int[] random = new[] { 7, 4, 5, 1, 4, 9, 9, 9, 1, 2, 7, 3 };

            //Quick Sort
            System.Console.WriteLine("Quick Sort");
            //Unsorted Print
            System.Console.WriteLine("Unsorted Arrays:");

            System.Console.Write('\t');
            foreach (int e in reversed)
            {
                System.Console.Write(e.ToString());
                System.Console.Write(" ");
            }
            System.Console.Write("\n\t");
            foreach (int e in random)
            {
                System.Console.Write(e.ToString());
                System.Console.Write(" ");
            }
            //Quick Sort
            Sort(reversed);
            Sort(random);
            //Sorted Print
            System.Console.WriteLine("\nSorted Arrays:");

            System.Console.Write('\t');
            foreach (int e in reversed)
            {
                System.Console.Write(e.ToString());
                System.Console.Write(" ");
            }
            System.Console.Write("\n\t");
            foreach (int e in random)
            {
                System.Console.Write(e.ToString());
                System.Console.Write(" ");
            }
            System.Console.Write("\n");
        }
    }
}
