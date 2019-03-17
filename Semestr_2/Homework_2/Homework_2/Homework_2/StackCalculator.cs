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
                    try
                    {
                        return firstNumber / secondNumber;
                    }
                    catch
                    {
                        throw;
                    }
            }
            return 0;
        }

        public int DoCalculation(string expression)
        {
            string[] literals = expression.Split(' ');
            try
            {
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
                        stack.Add(DoOperation(firstNumber, secondNumber, literal));
                    }
                    else
                    {
                        throw new ArgumentException();
                    }
                }

                var buffer = stack.Remove();
                return buffer;
            }
            catch
            {
                throw;
            }
        }
    }
}
