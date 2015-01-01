using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
/**
 * Stable
 * Θ(n) extra space for arrays (as shown)
 * Θ(lg(n)) extra space for linked lists
 * Θ(n·lg(n)) time
 * Not adaptive
 * Does not require random access to data
 */
/**
 * This code was strongly influenced from:
 * http://stackoverflow.com/questions/15835805/mergesort-algorithm-in-c-sharp
 */

namespace SortingAlgorithms.MergeSort
{
    class MergeSort
    {
        public static void Sort<T>(T[] array) where T : IComparable<T>
        {
            if (array != null && array.Length > 1)
            {
                Sort(array, 0, array.Length);
            }
        }
        private static void Sort<T>(T[] array, int low, int high) where T : IComparable<T>
        {
            //variables
            int N = high - low; //number of items being sorted
            int mid = low + (N / 2); //middle index
            
            //base case
            if (N <= 1)
                return;
            //recursively split
            Sort(array, low, mid);
            Sort(array, mid, high);

            //merge into new array
            T[] temp = new T[N];
            int i = low, j = mid;
            for (int k = 0; k < N; k++)
            {
                //base cases
                if (i == mid)//left side completely sorted
                {
                    temp[k] = array[j];
                    j++;
                }
                else if (j == high)//right side completely sorted
                {
                    temp[k] = array[i];
                    i++;
                }
                //comparisons
                else if (array[i].CompareTo(array[j]) <= 0)//i precedes j
                {
                    temp[k] = array[i];
                    i++;
                }
                else//j precedes i
                {
                    temp[k] = array[j];
                    j++;
                }
            }
            //copy temp array into current
            for (int k = low, z=0; k < high && z < temp.Length; k++,z++)
            {
                array[k] = temp[z];
            }

        }
        public static void Test()
        {
            int[] reversed = new[] { 9, 8, 7, 6, 5, 4, 3, 2, 1 };
            int[] random = new[] { 7, 4, 5, 1, 4, 9, 9, 9, 1, 2, 7, 3 };

            //Merge Sort
            System.Console.WriteLine("Merge Sort");
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
            //Merge Sort
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
        }
    }
}
