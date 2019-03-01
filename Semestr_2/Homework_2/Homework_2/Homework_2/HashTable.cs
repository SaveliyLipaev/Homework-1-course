using System;
using System.Collections.Generic;

namespace Homework_2
{
    class HashTable
    {
        private List<List> Buckets;
        private long amountElements = 0;

        public HashTable(int initialSize)
        {
            Buckets = new List<List>();

            for (var i = 0; i < initialSize; ++i)
            {
                Buckets.Add(new List());
            }
        }

        public HashTable() : this(20)
        { }

        private int HashFunction(string str)
        {
            int prime = 31;
            int sum = 0;

            for (var i = 0; i < str.Length; ++i)
            {
                sum = sum + str[i] * prime;
                prime *= prime;
            }

            if (sum < 0)
            {
                return -sum;
            }

            return sum;
        }

        private double LoadFactor() => (double)amountElements / Buckets.Count;

        private void Extension()
        {
            var NewBuckets = new List<List>();

            for (var i = 0; i < 2 * Buckets.Count + 1; ++i)
            {
                NewBuckets.Add(new List());
            }

            foreach (var oldList in Buckets)
            {
                for (var i = 0; i < oldList.Size(); ++i)
                {
                    var str = oldList.Remove();
                    NewBuckets[HashFunction(str) % NewBuckets.Count].Add(str);
                }
            }
            Buckets = NewBuckets;
        }

        private void CheckDimension()
        {
            if (LoadFactor() > 0.76)
            {
                Extension();
            }
        }

        public void Add(string str)
        {
            Buckets[HashFunction(str) % Buckets.Count].Add(str);
            ++amountElements;
            CheckDimension();
        }

        public void Remove(string str)
        {
            var hash = HashFunction(str) % Buckets.Count;
            var position = Buckets[hash].FindPosition(str);

            if (position != -1)
            {
                Buckets[hash].RemovePosition(position);
                --amountElements;
            }
        }

        public bool Affiliation(string str) => Buckets[HashFunction(str) % Buckets.Count].FindPosition(str) != -1;

        public void PrintHashTable()
        {
            foreach(var list in Buckets)
            {
                list.PrintList();
            }
        }
    }
}