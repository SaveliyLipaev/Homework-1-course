using Microsoft.VisualStudio.TestTools.UnitTesting;
using Calculator;
using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Calculator.Tests
{
    [TestClass()]
    public class ResultExpressionTests
    {
        [TestMethod()]
        [ExpectedException(typeof(System.InvalidOperationException))]
        public void ResultExpressionBadCharactersTest()
        {
            ResultExpression.Result("3+3*s+1");
        }

        [TestMethod()]
        [ExpectedException(typeof(System.InvalidOperationException))]
        public void ResultExpressionInvalidInputTest()
        {
            ResultExpression.Result("(3*)");
        }

        [TestMethod()]
        public void ResultExpressionTest()
        {
            Assert.AreEqual(24, ResultExpression.Result("2*(10+2)"));
        }

        [TestMethod()]
        public void NegativeNumbersTest()
        {
            Assert.AreEqual(-20, ResultExpression.Result("10-(6/2)*10"));
        }

        [TestMethod()]
        [ExpectedException(typeof(System.DivideByZeroException))]
        public void DivisionByZeroTest()
        {
            Assert.AreEqual(-1, ResultExpression.Result("3/0"));
        }
    }
}