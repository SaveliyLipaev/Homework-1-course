using Microsoft.VisualStudio.TestTools.UnitTesting;
using Homework_2;
using System;

namespace Homework_2.Tests
{
    [TestClass()]
    public class ListStackIntTests
    {
        [TestInitialize]
        public void Initialize()
        {
            stack = new ListStackInt();
        }

        [TestMethod()]
        public void AddNotEmptyTest()
        {
            stack.Add(5);
            Assert.IsFalse(stack.IsEmpty());
        }

        [TestMethod()]
        public void RemoveTest()
        {
            stack.Add(5);
            Assert.AreEqual(5, stack.Remove());
        }

        [TestMethod()]
        public void RemoveTwoElementsTest()
        {
            stack.Add(5);
            stack.Add(8);
            Assert.AreEqual(8, stack.Remove());
            Assert.AreEqual(5, stack.Remove());
        }

        [TestMethod]
        public void RemoveFromEmptyStackTest()
        {
            stack.Remove();
        }

        [TestMethod]
        public void AddMoreElements()
        {
            for (var i = 0; i < 1500; ++i)
            {
                stack.Add(i);
            }
        }

        private ListStackInt stack;
    }
}