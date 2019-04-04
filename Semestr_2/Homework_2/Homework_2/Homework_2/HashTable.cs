using System;

namespace Homework_2
{
    public class HashTable : IHashTable
    {
        private ListString[] buckets;
        private IHashFunction hashFunction;
        public long AmountOfElements { get; private set; }

        public HashTable(int initialSize, IHashFunction hashFunction)
        {
            buckets = new ListString[initialSize];
            this.hashFunction = hashFunction;

            for (var i = 0; i < initialSize; ++i)
            {
                buckets[i] = new ListString();
            }
        }

        public HashTable() : this(20, new AdditiveHashFunction())
        { }

        public HashTable(int initialSize) : this(initialSize, new AdditiveHashFunction())
        { }

        public HashTable(IHashFunction hashFunction) : this(20, hashFunction)
        { }

        private double LoadFactor() => (double)AmountOfElements / buckets.Length;

        private void Extension()
        {
            var newBuckets = new ListString[2 * buckets.Length + 1] ;

            for (var i = 0; i < newBuckets.Length; ++i)
            {
                newBuckets[i] = new ListString();
            }

            foreach (var oldList in buckets)
            {
                for (var i = 0; i < oldList.Size(); ++i)
                {
                    var str = oldList.Remove();
                    var hash = hashFunction.HashFunction(str) % newBuckets.Length;
                    hash = hash >= 0 ? hash : -hash;
                    newBuckets[hash].Add(str);
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
            if (str == null) 
            {
                return;
            }

            var hash = hashFunction.HashFunction(str) % buckets.Length;
            hash = hash >= 0 ? hash : -hash;
            buckets[hash].Add(str);

            ++AmountOfElements;
            CheckDimension();
        }

        public void Remove(string str)
        {
            if (str == null) 
            {
                return;
            }
            var hash = hashFunction.HashFunction(str) % buckets.Length;
            hash = hash >= 0 ? hash : -hash;
            var position = buckets[hash].FindPosition(str);

            if (position != -1)
            {
                buckets[hash].RemovePosition(position);
                --AmountOfElements;
            }
        }

        public bool IsBelongs(string str)
        {
            var hash = hashFunction.HashFunction(str) % buckets.Length;
            hash = hash >= 0 ? hash : -hash;
            return buckets[hash].FindPosition(str) != -1;
        }

        public void PrintHashTable()
        {
            foreach(var list in buckets)
            {
                list.PrintList();
            }
        }
    }
}