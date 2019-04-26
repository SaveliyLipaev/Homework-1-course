using Microsoft.VisualStudio.TestTools.UnitTesting;
using System.Collections.Generic;

namespace Set.Tests
{
    [TestClass()]
    public class MySetTests
    {
        private MySet<int> set;
        private List<int> list;

        [TestInitialize]
        public void Initialize()
        {
            list = new List<int>() { 1, 3, 5, 7 };
            set = new MySet<int>();
        }

        [TestMethod()]
        public void AddTest()
        {
            set.Add(1);
            Assert.AreEqual(1, set.Count);
        }

        [TestMethod()]
        public void ClearTest()
        {
            set.Add(1);
            set.Clear();
            Assert.AreEqual(0, set.Count);
        }

        [TestMethod()]
        public void ContainsTrueTest()
        {
            set.Add(1);
            Assert.IsTrue(set.Contains(1));
        }

        [TestMethod()]
        public void ContainsFalseTest()
        {
            set.Add(1);
            Assert.IsFalse(set.Contains(2));
        }

        [TestMethod()]
        public void CopyToTest()
        {
            var array = new int[] { 1, 2, 3, 4 };
            set.Add(5);
            set.Add(6);
            set.CopyTo(array, 2);
            Assert.AreEqual(6, array[3]);
        }

        [TestMethod]
        [ExpectedException(typeof(System.ArgumentOutOfRangeException))]
        public void CopyToArgumentOutOfRangeExceptionTest()
        {
            var array = new int[] { 1, 2, 3, 4 };
            set.Add(5);
            set.CopyTo(array, 4);
        }

        [TestMethod]
        [ExpectedException(typeof(System.ArgumentException))]
        public void CopyToArgumentExceptionTest()
        {
            var array = new int[] { 1, 2, 3, 4 };
            set.Add(5);
            set.Add(6);
            set.CopyTo(array, 3);
        }

        [TestMethod()]
        public void RemoveCountTest()
        {
            set.Add(1);
            set.Remove(1);
            Assert.AreEqual(0, set.Count);
        }

        [TestMethod()]
        public void RemoveTrueTest()
        {
            set.Add(1);
            Assert.IsTrue(set.Remove(1));
        }

        [TestMethod()]
        public void RemoveFalseTest()
        {
            set.Add(1);
            Assert.IsFalse(set.Remove(2));
        }

        [TestMethod()]
        public void ExceptWithRemoveElementTest()
        {
            set.Add(1);
            set.Add(2);
            set.Add(3);
            set.ExceptWith(list);
            Assert.IsFalse(set.Contains(1));
        }

        [TestMethod()]
        public void ExceptWithDontRemoveGoodElementTest()
        {
            set.Add(1);
            set.Add(2);
            set.Add(3);
            set.ExceptWith(list);
            Assert.IsTrue(set.Contains(2));
        }

        [TestMethod()]
        public void ExceptWithCountTest()
        {
            set.Add(1);
            set.Add(2);
            set.Add(3);
            set.ExceptWith(list);
            Assert.AreEqual(1, set.Count);
        }

        [TestMethod()]
        public void IntersectWithRemoveElementTest()
        {
            set.Add(1);
            set.Add(2);
            set.Add(3);
            set.IntersectWith(list);
            Assert.IsFalse(set.Contains(2));
        }

        [TestMethod()]
        public void IntersectWithDontRemoveGoodElementTest()
        {
            set.Add(1);
            set.Add(2);
            set.Add(3);
            set.IntersectWith(list);
            Assert.IsTrue(set.Contains(1));
        }

        [TestMethod()]
        public void IntersectWithCountTest()
        {
            set.Add(1);
            set.Add(2);
            set.Add(3);
            set.IntersectWith(list);
            Assert.AreEqual(2, set.Count);
        }

        [TestMethod()]
        public void IsProperSubsetOfTrueTest()
        {
            set.Add(1);
            set.Add(3);
            Assert.IsTrue(set.IsProperSubsetOf(list));
        }

        [TestMethod()]
        public void IsProperSubsetOfFalseTest()
        {
            set.Add(2);
            set.Add(3);
            Assert.IsFalse(set.IsProperSubsetOf(list));
        }

        [TestMethod()]
        public void IsProperSubsetOfDontProperTest()
        {
            set.Add(1);
            set.Add(3);
            set.Add(5);
            set.Add(7);
            Assert.IsFalse(set.IsProperSubsetOf(list));
        }

        [TestMethod()]
        public void IsProperSupersetOfTrueTest()
        {
            set.Add(1);
            set.Add(3);
            set.Add(5);
            set.Add(7);
            set.Add(8);
            Assert.IsTrue(set.IsProperSupersetOf(list));
        }

        [TestMethod()]
        public void IsProperSupersetOfFalseTest()
        {
            set.Add(1);
            set.Add(3);
            set.Add(5);
            set.Add(8);
            Assert.IsFalse(set.IsProperSupersetOf(list));
        }

        [TestMethod()]
        public void IsProperSupersetOfDontPropperTest()
        {
            set.Add(1);
            set.Add(3);
            set.Add(5);
            set.Add(7);
            Assert.IsFalse(set.IsProperSupersetOf(list));
        }

        [TestMethod()]
        public void IsSubsetOfTrueTest()
        {
            set.Add(1);
            set.Add(3);
            Assert.IsTrue(set.IsSubsetOf(list));
        }

        [TestMethod()]
        public void IsSubsetOfFalseTest()
        {
            set.Add(2);
            set.Add(3);
            Assert.IsFalse(set.IsSubsetOf(list));
        }

        [TestMethod()]
        public void IsSubsetOfDontProperTest()
        {
            set.Add(1);
            set.Add(3);
            set.Add(5);
            set.Add(7);
            Assert.IsTrue(set.IsSubsetOf(list));
        }

        [TestMethod()]
        public void IsSupersetOfTrueTest()
        {
            set.Add(1);
            set.Add(3);
            set.Add(5);
            set.Add(7);
            set.Add(8);
            Assert.IsTrue(set.IsSupersetOf(list));
        }

        [TestMethod()]
        public void IsSupersetOfFalseTest()
        {
            set.Add(1);
            set.Add(3);
            set.Add(5);
            set.Add(8);
            Assert.IsFalse(set.IsSupersetOf(list));
        }

        [TestMethod()]
        public void IsSupersetOfDontPropperTest()
        {
            set.Add(1);
            set.Add(3);
            set.Add(5);
            set.Add(7);
            Assert.IsTrue(set.IsSupersetOf(list));
        }

        [TestMethod()]
        public void OverlapsTrueTest()
        {
            set.Add(1);
            Assert.IsTrue(set.Overlaps(list));
        }

        [TestMethod()]
        public void OverlapsFalseTest()
        {
            set.Add(2);
            Assert.IsFalse(set.Overlaps(list));
        }

        [TestMethod()]
        public void SetEqualsTrueTest()
        {
            set.Add(1);
            set.Add(3);
            set.Add(5);
            set.Add(7);
            Assert.IsTrue(set.SetEquals(list));
        }

        [TestMethod()]
        public void SetEqualsFalseTest()
        {
            set.Add(1);
            set.Add(3);
            set.Add(7);
            Assert.IsFalse(set.SetEquals(list));
        }

        [TestMethod()]
        public void SymmetricExceptWithTest()
        {
            set.Add(1);
            set.Add(3);
            set.Add(8);
            set.SymmetricExceptWith(list);
            Assert.IsTrue(set.Contains(8));
            Assert.IsFalse(set.Contains(3));
            Assert.IsTrue(set.Contains(5));
        }

        [TestMethod()]
        public void UnionWithTest()
        {
            set.Add(2);
            set.UnionWith(list);
            Assert.IsTrue(set.Contains(1));
        }

        [TestMethod()]
        public void UnionWithCountTest()
        {
            set.Add(2);
            set.UnionWith(list);
            Assert.AreEqual(5, set.Count);
        }
    }
}