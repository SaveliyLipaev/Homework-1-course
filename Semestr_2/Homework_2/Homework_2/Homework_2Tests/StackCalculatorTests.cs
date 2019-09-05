using Microsoft.VisualStudio.TestTools.UnitTesting;
using Homework_2;
using System;

namespace Homework_2.Tests
{
    [TestClass()]
    public class StackCalculatorTests
    {
        [TestInitialize]
        public void Initialize()
        {
            calc = new StackCalculator(new ListStackInt());
        }

        [TestMethod()]
        [ExpectedException(typeof(System.ArgumentException))]
        public void DoCalculationBadCharactersTest()
        {
            calc.DoCalculation("3 3 s +");
        }

        [TestMethod()]
        [ExpectedException(typeof(System.ArgumentException))]
        public void DoCalculationInvalidInputTest()
        {
            calc.DoCalculation("3 3 3 + ");
        }

        [TestMethod()]
        public void DoCalculationTest()
        {
            Assert.AreEqual(21, calc.DoCalculation("3 3 4 + *"));
        }

        [TestMethod()]
        public void NegativeNumbersTest()
        {
            Assert.AreEqual(-21, calc.DoCalculation("3 -3 -4 + *"));
        }

        [TestMethod()]
        [ExpectedException(typeof(System.DivideByZeroException))]
        public void DivisionByZeroTest()
        {
            Assert.AreEqual(-1, calc.DoCalculation("3 0 /"));
        }

        private StackCalculator calc;
    }
}