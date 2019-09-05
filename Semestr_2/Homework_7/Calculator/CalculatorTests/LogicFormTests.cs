using Microsoft.VisualStudio.TestTools.UnitTesting;

namespace Calculator.Tests
{
    [TestClass()]
    public class LogicFormTests
    {
        private LogicForm logicForm;
        [TestInitialize]
        public void Initialize()
        {
            logicForm = new LogicForm();
        }

        [TestMethod()]
        public void ButtonClickNumberTest()
        {
            Assert.AreEqual("0,3", logicForm.ButtonClickNumber("0,", "3"));
        }

        [TestMethod()]
        public void ButtonClickNumberDeleteNullTest()
        {
            Assert.AreEqual("3", logicForm.ButtonClickNumber("0", "3"));
        }

        [TestMethod()]
        public void ButtonClickOperatorTest()
        {
            string result = "3";
            Assert.AreEqual("3+", logicForm.ButtonClickOperator(result, "+"));
        }

        [TestMethod()]
        public void ButtonClickSecondOperatorTest()
        {
            string result = "3+";
            Assert.AreEqual("3*", logicForm.ButtonClickOperator(result, "*"));
        }

        [TestMethod()]
        public void ButtonClickOperatorAfterPointTest()
        {
            string result = "3,";
            Assert.AreEqual("3,", logicForm.ButtonClickOperator(result, "*"));
        }

        [TestMethod()]
        public void ButtonClickLeftBranchNotOperatorTest()
        {
            string result = "10";
            Assert.AreEqual("10", logicForm.ButtonClickLeftBranch(result));
        }

        [TestMethod()]
        public void ButtonClickLeftBranchAfterNullStringTest()
        {
            string result = "0";
            Assert.AreEqual("(", logicForm.ButtonClickLeftBranch(result));
        }


        [TestMethod()]
        public void ButtonClickLeftBranchTest()
        {
            string result = "2*";
            Assert.AreEqual("2*(", logicForm.ButtonClickLeftBranch(result));
        }

        [TestMethod()]
        public void ButtonClickRightBranchNullStringBranchTest()
        {
            string result = "0";
            Assert.AreEqual("0", logicForm.ButtonClickRightBranch(result));
        }

        [TestMethod()]
        public void ButtonClickRightBranchNotLeftBranchTest()
        {
            string result = "0";
            result = logicForm.ButtonClickNumber(result, "3");
            result = logicForm.ButtonClickOperator(result, "*");
            result = logicForm.ButtonClickNumber(result, "2");
            Assert.AreEqual("3*2", logicForm.ButtonClickRightBranch(result));
        }

        [TestMethod()]
        public void ButtonClickRightBranchTest()
        {
            string result = "0";
            result = logicForm.ButtonClickLeftBranch(result);
            result = logicForm.ButtonClickNumber(result, "3");
            result = logicForm.ButtonClickOperator(result, "*");
            result = logicForm.ButtonClickNumber(result, "2");
            Assert.AreEqual("(3*2)", logicForm.ButtonClickRightBranch(result));
        }

        [TestMethod()]
        public void ButtonClickDeleteLastElementNullTest()
        {
            string result = "0";
            Assert.AreEqual("0", logicForm.ButtonClickDeleteLastElement(result));
        }

        [TestMethod()]
        public void ButtonClickDeleteLastElementTest()
        {
            string result = "0";
            result = logicForm.ButtonClickLeftBranch(result);
            result = logicForm.ButtonClickNumber(result, "3");
            result = logicForm.ButtonClickOperator(result, "*");
            result = logicForm.ButtonClickNumber(result, "2");
            Assert.AreEqual("(3*", logicForm.ButtonClickDeleteLastElement(result));
        }

        [TestMethod()]
        public void ButtonDeleteAllTest()
        {
            string result = "0";
            result = logicForm.ButtonClickLeftBranch(result);
            result = logicForm.ButtonClickNumber(result, "3");
            result = logicForm.ButtonClickOperator(result, "*");
            result = logicForm.ButtonClickNumber(result, "2");
            result = logicForm.ButtonDeleteAll();
            Assert.AreEqual("0", result);
        }
    }
}