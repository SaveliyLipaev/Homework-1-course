using Microsoft.VisualStudio.TestTools.UnitTesting;
using HomeWork_4._1;
using System;

namespace HomeWork_4._1.Tests
{
    [TestClass()]
    public class ParseTreeTests
    {
        [TestMethod()]
        public void ParseTreeResultTest()
        {
            var tree = new ParseTree("( * ( + 1 1 ) 2 )");
            Assert.AreEqual(4, tree.Result());
        }

        [TestMethod()]
        public void ParseTreeResultBigTest()
        {
            var tree = new ParseTree("( ^ ( * ( + ( - 8 6 ) ( * 3 ( / 120 10 ) ) 4 ) 2 )");
            Assert.AreEqual(23104, tree.Result());
        }

        [TestMethod()]
        [ExpectedException(typeof(System.DivideByZeroException))]
        public void ParseTreeResultDivideByZeroTest()
        {
            var tree = new ParseTree("( / ( * 2 4 ) ( - 2 2 ) )");
            tree.Result();
        }

        [TestMethod()]
        [ExpectedException(typeof(System.ArgumentException))]
        public void ParseTreeCreateArgumentExceptioNumberInsteadOfOperatorTest()
        {
            var tree = new ParseTree("( 4 ( + 4 4 ) 4");
            tree.Result();
        }

        [TestMethod()]
        [ExpectedException(typeof(System.ArgumentException))]
        public void ParseTreeBadSymbolsInStringInOperatorTest()
        {
            var tree = new ParseTree("( * ( i 7 8 ) 8 )");
            tree.Result();
        }

        [TestMethod()]
        [ExpectedException(typeof(System.ArgumentException))]
        public void ParseTreeBadSymbolsInStringInOperandTest()
        {
            var tree = new ParseTree("( * ( * o 8 ) 8 )");
        }

        [TestMethod()]
        [ExpectedException(typeof(System.ArgumentException))]
        public void ParseTreeForgettingSpaceTest()
        {
            var tree = new ParseTree("( * (+ 7 8 ) 8 )");
        }

        [TestMethod()]
        [ExpectedException(typeof(System.ArgumentException))]
        public void ParseTreeNegativeErectionTest()
        {
            var tree = new ParseTree("( ^ ( + 7 8 ) ( - 3 5 )");
            tree.Result();
        }

        [TestMethod()]
        [ExpectedException(typeof(System.ArgumentException))]
        public void ParseTreeMoreNumberWithoutOperandTest()
        {
            var tree = new ParseTree("( * ( + 1 1 2 ) 2 )");
            tree.Result();
        }

        [TestMethod()]
        [ExpectedException(typeof(System.ArgumentException))]
        public void ParseTreeExtraLeftBracketOneTest()
        {
            var tree = new ParseTree("( * ( + ( 1 2 ) 2 )");
            tree.Result();
        }

        [TestMethod()]
        [ExpectedException(typeof(System.ArgumentException))]
        public void ParseTreeExtraLeftBracketTwoTest()
        {
            var tree = new ParseTree("( * ( + 1 ( 2 ) 2 )");
            tree.Result();
        }
    }
}