using System;


namespace Homework_2
{
    public class StackCalculator : IStackCalculator
    {
        private IStack stack;

        public StackCalculator(IStack stack)
        {
            this.stack = stack;
        }

        private static bool IsOperator(string str) => str == "+" || str == "-" || str == "*" || str == "/";

        private static int DoOperation(int firstNumber, int secondNumber, string operation)
        {
            switch(operation)
            {
                case "+":
                    return firstNumber + secondNumber;
                case "-":
                    return firstNumber - secondNumber;
                case "*":
                    return firstNumber * secondNumber;
                case "/":
                    return firstNumber / secondNumber;
            }
            return 0;
        }

        public int DoCalculation(string expression)
        {
            string[] literals = expression.Split(' ');

                foreach (var literal in literals)
                {
                    if (int.TryParse(literal, out int result))
                    {
                        stack.Add(result);
                    }
                    else if (IsOperator(literal))
                    {
                        int secondNumber = stack.Remove();
                        int firstNumber = stack.Remove();
                        if(secondNumber == 0 && literal == "/")
                        {
                            return -1;
                        }
                        stack.Add(DoOperation(firstNumber, secondNumber, literal));
                    }
                    else
                    {
                        return -1;
                    }
                }

                var buffer = stack.Remove();
                if (!stack.IsEmpty())
                {
                    return -1;
                }

                return buffer;
        }
    }
}
