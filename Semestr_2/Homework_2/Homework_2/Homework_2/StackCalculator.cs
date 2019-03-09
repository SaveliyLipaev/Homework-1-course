using System;


namespace Homework_2
{
    class StackCalculator
    {
        private IStack stack;

        public StackCalculator(IStack stack)
        {
            this.stack = stack;
        }

        private static bool IsOperator(string str) => str == "+" || str == "-" || str == "*" || str == "/";

        private static int DoOperation(int firstNumber, int secondNimber, string operation)
        {
            switch(operation)
            {
                case "+":
                    return firstNumber + secondNimber;
                case "-":
                    return firstNumber - secondNimber;
                case "*":
                    return firstNumber * secondNimber;
                case "/":
                    return firstNumber / secondNimber;
            }
            //кинуть исключение
            return -1;
        }

        public int DoCalculation(string expression)
        {
            string[] literals = expression.Split(' ');

            foreach(var literal in literals)
            {
                if (int.TryParse(literal, out int result))
                {
                    stack.Add(result);
                }
                else if (IsOperator(literal))
                {
                    int secondNumber = stack.Remove();
                    int firstNumber = stack.Remove();
                    stack.Add(DoOperation(firstNumber, secondNumber, literal));
                }
                //кинуть еще исключение
            }

            return stack.Remove();
        }
    }
}
