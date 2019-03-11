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
                        throw new ArgumentOutOfRangeException("Встреча непредвиденных символов");
                    }
                }

                var buffer = stack.Remove();
                if (!stack.IsEmpty())
                {
                    throw new Exception("Некорректный ввод");
                }

                return buffer;
            }
            catch(ArgumentOutOfRangeException exception)
            {
                Console.WriteLine(exception.Message);
            }
            catch(Exception exception)
            {
                Console.WriteLine(exception.Message);
            }
        }
    }
}
