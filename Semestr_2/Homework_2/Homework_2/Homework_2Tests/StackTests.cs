using Microsoft.VisualStudio.TestTools.UnitTesting;
using Homework_2;
using System;

namespace Homework_2.Tests
{
    [TestClass()]
    public class StackTests
    {
        [TestInitialize]
        public void Initialize()
        {
            arrayStack = new ArrayStack();
            listStack = new ListStackInt();
        }

        public void AddNotEmptyTest(IStack stack)
        {
            stack.Push(5);
            Assert.IsFalse(stack.IsEmpty());
        }

        public void RemoveTest(IStack stack)
        {
            stack.Push(5);
            Assert.AreEqual(5, stack.Pop());
        }

        public void RemoveFromEmptyStackTest(IStack stack)
        {
            stack.Pop();
        }

        public void AddMoreElements(IStack stack)
        {
            for (var i = 0; i < 1500; ++i)
            {
                stack.Push(i);
            }
        }

        public void RemoveTwoElementsTest(IStack stack)
        {
            stack.Push(5);
            stack.Push(8);
            Assert.AreEqual(8, stack.Pop());
            Assert.AreEqual(5, stack.Pop());
        }

        [TestMethod()]
        public void AddNotEmptyArrayStackTest() => AddNotEmptyTest(arrayStack);

        [TestMethod()]
        public void AddNotEmptyListStackTest() => AddNotEmptyTest(listStack);

        [TestMethod()]
        public void RemoveArrayStackTest() => RemoveTest(arrayStack);

        [TestMethod()]
        public void RemoveListStackTest() => RemoveTest(listStack);

        [TestMethod()]
        public void RemoveTwoElementsArrayStackTest() => RemoveTwoElementsTest(arrayStack);

        [TestMethod()]
        public void RemoveTwoElementsListStackTest() => RemoveTwoElementsTest(listStack);

        [TestMethod]
        [ExpectedException(typeof(System.InvalidOperationException))]
        public void RemoveFromEmptyArrayStackTest() => RemoveFromEmptyStackTest(arrayStack);

        [TestMethod]
        [ExpectedException(typeof(System.InvalidOperationException))]
        public void RemoveFromEmptyListStackTest() => RemoveFromEmptyStackTest(listStack);

        [TestMethod]
        public void AddMoreArrayStackElements() => AddMoreElements(arrayStack);

        [TestMethod]
        public void AddMoreListStackElements() => AddMoreElements(listStack);

        private ArrayStack arrayStack;
        private ListStackInt listStack;
    }
}