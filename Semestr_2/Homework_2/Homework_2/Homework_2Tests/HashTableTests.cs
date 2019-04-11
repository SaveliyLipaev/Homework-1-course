using Microsoft.VisualStudio.TestTools.UnitTesting;
using Homework_2;
using System;

namespace Homework_2.Tests
{
    [TestClass()]
    public class HashTableTests
    {
        private HashTable hashTableAddler;
        private HashTable hashTableAdditive;

        [TestInitialize]
        public void Initialize()
        {
            hashTableAddler = new HashTable(new AddlerHashFunction());
            hashTableAdditive = new HashTable(new AdditiveHashFunction());
        }

        public void AddMoreElementInHashTable(HashTable hashTable)
        {
            for (var i = 0; i < 1500; ++i)
            {
                hashTable.Add(i.ToString());
            }
            Assert.AreEqual(1500, hashTable.AmountOfElements);
        }

        public void IsBelongsFalseInHashTableTest(HashTable hashTable)
        {
            hashTable.Add("999989");
            Assert.IsFalse(hashTable.IsBelongs("999988"));
        }

        public void IsBelongsTrueInHashTableTest(HashTable hashTable)
        {
            hashTable.Add("999989");
            Assert.IsTrue(hashTable.IsBelongs("999989"));
        }

        public void RemoveElementsHashTableTest(HashTable hashTable)
        {
            for (var i = 0; i < 15; ++i)
            {
                hashTable.Add(i.ToString());
            }
            hashTable.Remove(10.ToString());
            Assert.IsFalse(hashTable.IsBelongs(10.ToString()));
        }

        public void RemoveElemntsAmountElementsHashTableTest(HashTable hashTable)
        {
            for (var i = 0; i < 15; ++i)
            {
                hashTable.Add(i.ToString());
            }
            hashTable.Remove(10.ToString());
            Assert.AreEqual(14, hashTable.AmountOfElements);
        }

        [TestMethod]
        public void AddMoreElementInAdditiveHashTable() => AddMoreElementInHashTable(hashTableAdditive);

        [TestMethod]
        public void AddMoreElementInAddlerHashTable() => AddMoreElementInHashTable(hashTableAddler);

        [TestMethod]
        public void IsBelongsFalseInAddlerHashTableTest() => IsBelongsFalseInHashTableTest(hashTableAddler);

        [TestMethod]
        public void IsBelongsFalseInAdditiveHashTableTest() => IsBelongsFalseInHashTableTest(hashTableAdditive);

        [TestMethod]
        public void IsBelongsTrueInAddlerHashTableTest() => IsBelongsTrueInHashTableTest(hashTableAddler);

        [TestMethod]
        public void IsBelongsTrueInAdditiveHashTableTest() => IsBelongsTrueInHashTableTest(hashTableAdditive);

        [TestMethod]
        public void RemoveElementsAddlerHashTest() => RemoveElementsHashTableTest(hashTableAddler);

        [TestMethod]
        public void RemoveElementsAdditiveHashTest() => RemoveElementsHashTableTest(hashTableAdditive);

        [TestMethod]
        public void RemoveElemntsAmountElementsAdditiveHashTest() => RemoveElemntsAmountElementsHashTableTest(hashTableAdditive);

        [TestMethod]
        public void RemoveElemntsAmountElementsAddlerHashTest() => RemoveElemntsAmountElementsHashTableTest(hashTableAddler);
    }
}