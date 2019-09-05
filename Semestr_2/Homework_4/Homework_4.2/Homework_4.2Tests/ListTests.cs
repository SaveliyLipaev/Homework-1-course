using Microsoft.VisualStudio.TestTools.UnitTesting;
using Homework_4._2;
using System;

namespace Homework_4._2.Tests
{
    [TestClass]
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
            list.Add("5");
            Assert.IsFalse(list.IsEmpty());
        }

        [TestMethod()]
        public void RemoveTest()
        {
            list.Add("5");
            Assert.AreEqual("5", list.Remove());
        }

        [TestMethod()]
        public void RemoveTwoTest()
        {
            list.Add("5");
            list.Add("8");
            Assert.AreEqual("8", list.Remove());
            Assert.AreEqual("5", list.Remove());
        }

        [TestMethod]
        [ExpectedException(typeof(System.InvalidOperationException))]
        public void RemoveFromEmptyStackTest()
        {
            list.Remove();
        }

        [TestMethod]
        [ExpectedException(typeof(MissingItemException))]
        public void RemoveMissingItemStackTest()
        {
            list.Add("7");
            list.RemoveElement("8");
        }

        [TestMethod]
        public void AddMoreElements()
        {
            for (var i = 0; i < 1500; ++i)
            {
                list.Add(i.ToString());
            }
        }

        [TestMethod]
        public void RemoveElementTest()
        {
            list.Add("4");
            list.RemoveElement("4");

            Assert.IsFalse(!list.IsEmpty());
        }

        [TestMethod]
        public void RemoveElementReturnValueTest()
        {
            list.Add("4");
            Assert.AreEqual("4", list.Remove());
        }

        [TestMethod]
        public void RemoveElementMoreTest()
        {
            for (var i = 0; i < 15; ++i)
            {
                list.Add(i.ToString());
            }

            for (var i = 7; i < 15; ++i)
            {
                list.RemoveElement(i.ToString());
            }

            for (var i = 6; i >= 0; --i)
            {
                list.RemoveElement(i.ToString());
            }

            Assert.IsFalse(!list.IsEmpty());
        }

        [TestMethod]
        public void RemovePositionTest()
        {
            list.Add("1");
            list.Add("2");
            list.Add("3");

            list.RemovePosition(2);
            Assert.AreEqual("3", list.Remove());
            Assert.AreEqual("1", list.Remove());
        }

        [TestMethod]
        [ExpectedException(typeof(System.IndexOutOfRangeException))]
        public void RemoveBadPositionTest()
        {
            list.Add("1");
            list.Add("2");
            list.RemovePosition(5);
        }

        [TestMethod]
        [ExpectedException(typeof(System.IndexOutOfRangeException))]
        public void RemoveNegativPositionTest()
        {
            list.Add("1");
            list.Add("2");
            list.RemovePosition(-2);
        }

        [TestMethod]
        public void AddPositionTest()
        {
            list.Add("1");
            list.Add("3");
            list.AddPosition(2, "2");
            Assert.AreEqual("3", list.Remove());
            Assert.AreEqual("2", list.Remove());
            Assert.AreEqual("1", list.Remove());
        }

        [TestMethod]
        [ExpectedException(typeof(System.IndexOutOfRangeException))]
        public void AddBadPositionTest()
        {
            list.AddPosition(2, "1");
        }
    }
}          