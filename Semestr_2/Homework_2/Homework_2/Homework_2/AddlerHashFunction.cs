using System;


namespace Homework_2
{
    /// <summary>
    /// Класс реализующий метод возвращения хэш значения методом Адлера
    /// </summary>
    public class AddlerHashFunction : IHashFunction
    {
        /// <summary>
        /// Метод возвращает хэш значение от полученной строки
        /// </summary>
        public int HashFunction(string str)
        {
            int s1 = 1;
            int s2 = 0;

            foreach (var symbol in str)
            {
                s1 = (s1 + symbol) % 65521;
                s2 = (s2 + s1) % 65521;
            }
            s2 = (s2 << 16) + s1;
            return s2 < 0 ? -s2 : s2;
        }
    }
}
