using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace DataStructures.HashTable
{
    struct Bucket<T> where T : IComparable<T>
    {
        public List<T> Values { get; set; }
    }
    class HashTable<T> where T : IComparable<T>
    {
        public int Count { get; set; }
        protected Bucket<T>[] Buckets;

        public HashTable(int size)
        {
            Buckets = new Bucket<T>[size];
        }
        public T GetKey(T key){
            int index = Hash(key);
            return this.Buckets[index].Values.Where(t => t.CompareTo(key) == 0).ToList().FirstOrDefault();
        }
        public void StoreKey(T key){
            int index = Hash(key);
            Buckets[index].Values.Add(key);
        }
        protected int Hash(T key)
        {
            int i = key.GetHashCode();
            i %= Buckets.Length;
            return i;
        }
    }
}
