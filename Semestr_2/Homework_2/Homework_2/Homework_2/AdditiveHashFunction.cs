using System;


namespace Homework_2
{
    /// <summary>
    /// Класс реализующий аддитивный метод возвращения хэш значения
    /// </summary>
    public class AdditiveHashFunction : IHashFunction
    {
        /// <summary>
        /// Метод возвращает хэш значение от полученной строки
        /// </summary>
        public int HashFunction(string str)
        {
            int prime = 31;
            int sum = 0;

            for (var i = 0; i < str.Length; ++i)
            {
                sum = sum + str[i] * prime;
                prime *= prime;
            }

            return sum < 0 ? -sum : sum;
        }
    }
}
