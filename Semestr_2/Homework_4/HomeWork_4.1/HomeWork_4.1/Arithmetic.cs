using System;

/// <summary>
/// Пространство имен для разных операций
/// </summary>
namespace DoOperation
{
    /// <summary>
    /// Класс реализующий арфиметические операции
    /// </summary>
    public static class Arithmetic
    {
        /// <summary>
        /// Функция возвращающая результат вычисления
        /// </summary>
        /// <param name="operation">операция</param>
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

        /// <summary>
        /// Функция возводящая в степень
        /// </summary>
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
