using Microsoft.VisualStudio.TestTools.UnitTesting;
using System.Collections.Generic;

namespace _6._1.Tests
{
    [TestClass]
    public class FunctionForTaskTests
    {
        private List<int> listForTest;

        [TestInitialize]
        public void Initialize()
        {
            listForTest = new List<int>();

            for (var i = 1; i < 10; ++i)
            {
                listForTest.Add(i);
            }
        }

        [TestMethod()]
        public void MapTest()
        {
            var result = FunctionForTask.Map(listForTest, x => x * 2);

            for (var i = 0; i < 9; ++i)
            {
                Assert.AreEqual(listForTest[i] * 2, result[i]);
            }
        }

        [TestMethod()]
        public void FilterTest()
        {
            var result = FunctionForTask.Filter(listForTest, x => x % 2 == 0);
            for (var i = 2; i < 10; i *= 2)
            {
                Assert.AreEqual(i, result[i / 2 - 1]);
            }
            Assert.AreEqual(4, result.Count);
        }

        [TestMethod()]
        public void FoldTest()
        {
            Assert.AreEqual(362880, FunctionForTask.Fold(listForTest, 1, (acc, elem) => acc * elem));
        }

        [TestMethod]
        [ExpectedException(typeof(System.ArgumentException))]
        public void ArgumentExceptionInFuncTest()
        {
            var result = FunctionForTask.Filter(listForTest, null);
        }

        [TestMethod]
        [ExpectedException(typeof(System.ArgumentException))]
        public void ArgumentExceptionInListTest()
        {
            var result = FunctionForTask.Filter(null, x => x % 2 == 0);
        }
    }
}