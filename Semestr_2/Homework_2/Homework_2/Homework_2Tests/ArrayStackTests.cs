using Microsoft.VisualStudio.TestTools.UnitTesting;
using Homework_2;
using System;

namespace Homework_2.Tests
{
    [TestClass()]
    public class ArrayStackTests
    {
        [TestInitialize]
        public void Initialize()
        {
            stack = new ArrayStack();
        }

        [TestMethod()]
        public void AddNotEmptyTest()
        {
            stack.Push(5);
            Assert.IsFalse(stack.IsEmpty());
        }

        [TestMethod()]
        public void RemoveTest()
        {
            stack.Push(5);
            Assert.AreEqual(5, stack.Pop());
        }

        [TestMethod()]
        public void RemoveTwoElementsTest()
        {
            stack.Push(5);
            stack.Push(8);
            Assert.AreEqual(8, stack.Pop());
            Assert.AreEqual(5, stack.Pop());
        }

        [TestMethod]
        [ExpectedException(typeof(System.InvalidOperationException))]
        public void RemoveFromEmptyStackTest()
        {
            stack.Pop();
        }

        [TestMethod]
        public void AddMoreElements()
        {
            for (var i = 0; i < 1500; ++i)
            {
                stack.Push(i);
            }
        }

        private ArrayStack stack;
    }
}