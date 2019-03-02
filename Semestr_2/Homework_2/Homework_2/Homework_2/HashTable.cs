using System;

namespace Homework_2
{
    class HashTable
    {
        private List[] buckets;
        private long amountElements;

        public HashTable(int initialSize)
        {
            buckets = new List[initialSize];

            for (var i = 0; i < initialSize; ++i)
            {
                buckets[i] = new List();
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

            return sum < 0 ? -sum : sum;
        }

        private double LoadFactor() => (double)amountElements / buckets.Length;

        private void Extension()
        {
            List[] newBuckets = new List[2 * buckets.Length + 1] ;

            for (var i = 0; i < newBuckets.Length; ++i)
            {
                newBuckets[i] = new List();
            }

            foreach (var oldList in buckets)
            {
                for (var i = 0; i < oldList.Size(); ++i)
                {
                    var str = oldList.Remove();
                    newBuckets[HashFunction(str) % newBuckets.Length].Add(str);
                }
            }
            buckets = newBuckets;
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
            buckets[HashFunction(str) % buckets.Length].Add(str);
            ++amountElements;
            CheckDimension();
        }

        public void Remove(string str)
        {
            var hash = HashFunction(str) % buckets.Length;
            var position = buckets[hash].FindPosition(str);

            if (position != -1)
            {
                buckets[hash].RemovePosition(position);
                --amountElements;
            }
        }

        public bool IsBelongs(string str) => buckets[HashFunction(str) % buckets.Length].FindPosition(str) != -1;

        public void PrintHashTable()
        {
            foreach(var list in buckets)
            {
                list.PrintList();
            }
        }
    }
}