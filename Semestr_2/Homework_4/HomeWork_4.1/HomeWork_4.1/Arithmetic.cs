using System;

namespace DoOperation
{
    public static class Arithmetic
    {
        public static int Result(int firstNumber, int secondNumber, string operation)
        {
            switch (operation)
            {
                case "+":
                    return firstNumber + secondNumber;
                case "-":
                    return firstNumber - secondNumber;
                case "*":
                    return firstNumber * secondNumber;
                case "/":
                    return firstNumber / secondNumber;
                case "^":
                    return Exponentiation(firstNumber, secondNumber);
                default:
                    throw new ArgumentException($"Не удалось распознать операцию: {operation}, проверьте введенные данные");
            }
        }

        private static int Exponentiation(int number, int exponent)
        {
            int result = 1;
            if (exponent < 0)
            {
                throw new ArgumentException("В кольце целых чисел не может быть отрицательной степени");
            }

            for (var i = 0; i < exponent; ++i)
            {
                result *= number;
            }

            return result;
        }
    }
}
