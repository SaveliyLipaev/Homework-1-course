using Microsoft.VisualStudio.TestTools.UnitTesting;
using Test_1;
using System;

namespace Test_1.Tests
{
    [TestClass()]
    public class PriorityQueueTests
    {
        private PriorityQueue priorityOueue;

        [TestInitialize]
        public void Initialize()
        {
            priorityOueue = new PriorityQueue();
        }

        [TestMethod()]
        public void EnqueueTest()
        {
            priorityOueue.Enqueue(4, 5);
            Assert.IsFalse(priorityOueue.isEmpty());
        }

        [TestMethod()]
        public void EnqueueMoreElementsTest()
        {
            for (var i = 0; i < 1500; ++i)
            {
                priorityOueue.Enqueue(i, 1);
            }
        }

        [TestMethod()]
        public void DequeueTest()
        {
            priorityOueue.Enqueue(1, 5);
            priorityOueue.Enqueue(2, 6);

            Assert.AreEqual(2, priorityOueue.Dequeue());
        }

        [TestMethod()]
        public void DequeueDeleteElementsTest()
        {
            priorityOueue.Enqueue(1, 5);
            priorityOueue.Enqueue(2, 6);

            priorityOueue.Dequeue();
            priorityOueue.Dequeue();

            Assert.IsTrue(priorityOueue.isEmpty());
        }

        [TestMethod()]
        public void DequeueStandartTest()
        {
            priorityOueue.Enqueue(1, 5);
            priorityOueue.Enqueue(2, 1);
            priorityOueue.Enqueue(3, 3);
            priorityOueue.Enqueue(4, 3);

            Assert.AreEqual(1, priorityOueue.Dequeue());
            Assert.AreEqual(3, priorityOueue.Dequeue());
            Assert.AreEqual(4, priorityOueue.Dequeue());
            Assert.AreEqual(2, priorityOueue.Dequeue());
        }

        [TestMethod]
        [ExpectedException(typeof(EmptyQueueException))]
        public void DequeueFromEmptyQueueTest()
        {
            priorityOueue.Dequeue();
        }

        [TestMethod()]
        public void EnqueueAndDequeueMoreElementsTest()
        {
            for (var i = 0; i < 1500; ++i)
            {
                priorityOueue.Enqueue(i, 1);
            }

            for (var i = 0; i < 1500; ++i)
            {
                Assert.AreEqual(i, priorityOueue.Dequeue());
            }

            Assert.IsTrue(priorityOueue.isEmpty());
        }
    }
}