using System;

namespace Homework_2
{
    public interface IHashFunction
    {
        /// <summary>
        /// Функция, генерирущая хэш код
        /// </summary>
        /// <param name="str"></param>
        /// <returns></returns>
        int HashFunction(string str);
    }
}
