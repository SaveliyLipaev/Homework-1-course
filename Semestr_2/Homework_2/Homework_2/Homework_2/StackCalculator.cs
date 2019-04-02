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
            try
            {
                foreach (var literal in literals)
                {
                    if (int.TryParse(literal, out int result))
                    {
                        stack.Push(result);
                    }
                    else if (IsOperator(literal))
                    {
                        int secondNumber = stack.Pop();
                        int firstNumber = stack.Pop();
                        stack.Push(DoOperation(firstNumber, secondNumber, literal));
                    }
                    else
                    {
                        throw new ArgumentException("Невозможно вычислить, проверьте правильность записи");
                    }
                }

                var buffer = stack.Pop();
                if (!stack.IsEmpty())
                {
                    throw new ArgumentException("Невозможно вычислить, проверьте правильность записи");
                }

                return buffer;
            }
            catch
            {
                throw;
            }
        }
    }
}
