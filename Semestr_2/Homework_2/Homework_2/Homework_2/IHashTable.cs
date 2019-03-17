using System;


namespace Homework_2
{
    public interface IHashTable
    {
        /// <summary>
        /// Добавление значения в хэш таблицу
        /// </summary>
        /// <param name="str"></param>
        void Add(string str);

        /// <summary>
        /// Удаление значения из хэш таблицы
        /// </summary>
        /// <param name="str"></param>
        void Remove(string str);

        /// <summary>
        /// Возвращает true если значение есть в хэш таблице
        /// </summary>
        /// <param name="str"></param>
        /// <returns></returns>
        bool IsBelongs(string str);

        /// <summary>
        /// Распечатывает хэш таблицу
        /// </summary>
        void PrintHashTable();
    }
}
