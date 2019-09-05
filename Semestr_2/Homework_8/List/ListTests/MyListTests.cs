using Microsoft.VisualStudio.TestTools.UnitTesting;

namespace List.Tests
{
    [TestClass()]
    public class MyListTests
    {
        private MyList<int> list;

        [TestInitialize]
        public void Initialize()
        {
            list = new MyList<int>();
        }

        [TestMethod()]
        public void AddTest()
        {
            list.Add(1);
            Assert.AreEqual(1, list[0]);
        }

        [TestMethod()]
        public void AddNotEmptyTest()
        {
            list.Add(1);
            Assert.AreEqual(1, list.Count);
        }

        [TestMethod()]
        public void ClearTest()
        {
            list.Add(1);
            list.Clear();
            Assert.AreEqual(0, list.Count);
        }

        [TestMethod()]
        public void ContainsTrueTest()
        {
            list.Add(1);
            list.Add(2);
            Assert.IsTrue(list.Contains(2));
        }

        [TestMethod()]
        public void ContainsFalseTest()
        {
            list.Add(1);
            list.Add(2);
            Assert.IsFalse(list.Contains(3));
        }

        [TestMethod()]
        public void CopyToTest()
        {
            for (var i = 0; i < 10; ++i)
            {
                list.Add(i);
            }
            var mas = new int[20];
            list.CopyTo(mas, 9);
            for (var i = 9; i < 19; ++i)
            {
                Assert.AreEqual(list[i - 9], mas[i]);
            }
        }

        [TestMethod()]
        public void IndexOfTest()
        {
            list.Add(5);
            list.Add(10);
            list.Add(15);
            Assert.AreEqual(1, list.IndexOf(10));
        }

        [TestMethod()]
        public void IndexOfNotElementTest()
        {
            list.Add(5);
            list.Add(10);
            list.Add(15);
            Assert.AreEqual(-1, list.IndexOf(11));
        }

        [TestMethod()]
        public void InsertTest()
        {
            list.Add(5);
            list.Add(10);
            list.Add(15);
            list.Insert(1, 7);
            Assert.AreEqual(5, list[0]);
            Assert.AreEqual(7, list[1]);
            Assert.AreEqual(10, list[2]);
        }

        [TestMethod()]
        public void InsertCountTest()
        {
            list.Add(5);
            list.Add(10);
            list.Add(15);
            list.Insert(1, 7);
            Assert.AreEqual(4, list.Count);
        }

        [TestMethod()]
        public void RemoveCountTest()
        {
            list.Add(5);
            list.Add(10);
            list.Add(15);
            list.Remove(10);
            Assert.AreEqual(2, list.Count);
        }

        [TestMethod()]
        public void RemoveTest()
        {
            list.Add(5);
            list.Add(10);
            list.Add(15);
            list.Remove(10);
            Assert.AreEqual(15, list[1]);
        }

        [TestMethod()]
        public void RemoveAtCountTest()
        {
            list.Add(5);
            list.Add(10);
            list.Add(15);
            list.RemoveAt(1);
            Assert.AreEqual(2, list.Count);
        }

        [TestMethod()]
        public void RemoveAtTest()
        {
            list.Add(5);
            list.Add(10);
            list.Add(15);
            list.RemoveAt(1);
            Assert.AreEqual(5, list[0]);
            Assert.AreEqual(15, list[1]);
        }

        [TestMethod]
        [ExpectedException(typeof(System.ArgumentOutOfRangeException))]
        public void CopyToOutIndexTest()
        {
            var mas = new int[10];
            list.CopyTo(mas, 11);
        }

        [TestMethod]
        [ExpectedException(typeof(System.ArgumentException))]
        public void ArgumentException()
        {
            var mas = new int[2];
            list.Add(1);
            list.Add(2);
            list.CopyTo(mas, 1);
        }

        [TestMethod]
        [ExpectedException(typeof(System.ArgumentOutOfRangeException))]
        public void InsertOutIndexTest()
        {
            list.Add(1);
            list.Insert(3, 2);
        }

        [TestMethod]
        [ExpectedException(typeof(System.ArgumentOutOfRangeException))]
        public void RemoveAtOutIndexTest()
        {
            list.Add(1);
            list.RemoveAt(1);
        }
    }
}