using Microsoft.VisualStudio.TestTools.UnitTesting;
using Homework_4._2;
using System;

namespace Homework_4._2.Tests
{
    [TestClass()]
    public class ListTests
    {
        private List list;

        [TestInitialize]
        public void Initialize()
        {
            list = new List();
        }

        [TestMethod()]
        public void AddNotEmptyTest()
        {
            list.Add(5);
            Assert.IsFalse(list.IsEmpty());
        }

        [TestMethod()]
        public void RemoveTest()
        {
            list.Add(5);
            Assert.AreEqual(5, list.Remove());
        }

        [TestMethod()]
        public void RemoveTwoTest()
        {
            list.Add(5);
            list.Add(8);
            Assert.AreEqual(8, list.Remove());
            Assert.AreEqual(5, list.Remove());
        }

        [TestMethod]
        [ExpectedException(typeof(System.NullReferenceException))]
        public void RemoveFromEmptyStackTest()
        {
            list.Remove();
        }

        [TestMethod]
        [ExpectedException(typeof(MissingItemException))]
        public void RemoveMissingItemStackTest()
        {
            list.Add(7);
            list.RemoveElement(8);
        }

        [TestMethod]
        public void AddMoreElements()
        {
            for (var i = 0; i < 1500; ++i)
            {
                list.Add(i);
            }
        }
        
        [TestMethod]
        public void RemoveElementTest()
        {
            list.Add(4);
            list.RemoveElement(4);

            Assert.IsFalse(!list.IsEmpty());
        }

        [TestMethod]
        public void RemoveElementReturnValueTest()
        {
            list.Add(4);
            Assert.AreEqual(4, list.Remove());
        }

        [TestMethod]
        public void RemoveElementMoreTest()
        {
            for (var i = 0; i < 15; ++i)
            {
                list.Add(i);
            }

            for (var i = 7; i < 15; ++i)
            {
                list.RemoveElement(i);
            }

            for (var i = 6; i >= 0; --i)
            {
                list.RemoveElement(i);
            }

            Assert.IsFalse(!list.IsEmpty());
        }
           
    }      
}          