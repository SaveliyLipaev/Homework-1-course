using System;

namespace Homework_2
{
    /// <summary>
    /// Интерфейс хэш функции
    /// </summary>
    public interface IHashFunction
    {
        /// <summary>
        /// Функция, генерирущая хэш код
        /// </summary>
        /// <param name="str">Данные по которым получается хэш код</param>
        int HashFunction(string str);
    }
}
