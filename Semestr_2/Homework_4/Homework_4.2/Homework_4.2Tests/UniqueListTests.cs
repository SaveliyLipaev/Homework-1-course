using Microsoft.VisualStudio.TestTools.UnitTesting;
using Homework_4._2;
using System;

namespace Homework_4._2.Tests
{
    [TestClass]
    public class UniqueListTests
    {
        private UniqueList list;

        [TestInitialize]
        public void Initialize()
        {
            list = new UniqueList();
        }

        [TestMethod()]
        public void AddTest()
        {
            list.Add("4");
            Assert.IsFalse(list.IsEmpty());
        }

        [TestMethod()]
        public void AddMoreTest()
        {
            for (var i = 0; i < 1555; ++i)
            {
                list.Add(i.ToString());
            }
            Assert.IsFalse(list.IsEmpty());
        }

        [TestMethod()]
        [ExpectedException(typeof(AttemptAddAnExistingItemException))]
        public void AddTwoExistingItemTest()
        {
            list.Add("2");
            list.Add("2");
        }

        [TestMethod()]
        public void AddPositionTest()
        {
            for (var i = 0; i < 3; ++i)
            {
                list.AddPosition(i + 1, i.ToString());
            }

            for (var i = 0; i < 3; ++i)
            {
                Assert.AreEqual(i.ToString(), list.Remove());
            }
        }

        [TestMethod()]
        [ExpectedException(typeof(AttemptAddAnExistingItemException))]
        public void AddPositionTwoExistingItemTest()
        {
            list.AddPosition(1, "2");
            list.AddPosition(2, "2");
        }


    }
}