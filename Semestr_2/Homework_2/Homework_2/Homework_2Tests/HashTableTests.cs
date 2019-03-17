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

        [TestMethod]
        public void AddMoreElementInHashTable()
        {
            for (var i = 0; i < 1500; ++i)
            {
                hashTableAdditive.Add(i.ToString());
            }
            Assert.AreEqual(1500, hashTableAdditive.amountElements);
        }

        [TestMethod]
        public void IsBelongsFalseInAddlerHashTableTest()
        {
            hashTableAddler.Add("999989");
            Assert.AreEqual(false, hashTableAddler.IsBelongs("999988"));
        }

        [TestMethod]
        public void IsBelongsTrueInAddlerHashTableTest()
        {
            hashTableAddler.Add("999989");
            Assert.AreEqual(true, hashTableAddler.IsBelongs("999989"));
        }

        [TestMethod]
        public void IsBelongsFalseInAdditiveHashTableTest()
        {
            hashTableAddler.Add("999989");
            Assert.AreEqual(false, hashTableAdditive.IsBelongs("999988"));
        }

        [TestMethod]
        public void IsBelongsTrueInAdditiveHashTableTest()
        {
            hashTableAdditive.Add("999989");
            Assert.AreEqual(true, hashTableAdditive.IsBelongs("999989"));
        }

        [TestMethod]
        public void RemoveElementsAddlerHashTest()
        {
            for (var i = 0; i < 15; ++i)
            {
                hashTableAddler.Add(i.ToString());
            }
            hashTableAddler.Remove(10.ToString());
            Assert.AreEqual(false, hashTableAddler.IsBelongs(10.ToString()));
        }

        [TestMethod]
        public void RemoveElementsAdditiveHashTest()
        {
            for (var i = 0; i < 15; ++i)
            {
                hashTableAdditive.Add(i.ToString());
            }
            hashTableAdditive.Remove(10.ToString());
            Assert.AreEqual(false, hashTableAdditive.IsBelongs(10.ToString()));
        }

        [TestMethod]
        public void RemoveElemntsAmountElementsTest()
        {
            for (var i = 0; i < 15; ++i)
            {
                hashTableAdditive.Add(i.ToString());
            }
            hashTableAdditive.Remove(10.ToString());
            Assert.AreEqual(14, hashTableAdditive.amountElements);
        }
    }
}