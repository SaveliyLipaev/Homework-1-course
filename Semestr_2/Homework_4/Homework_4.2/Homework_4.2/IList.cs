using System;

namespace Homework_4._2
{
    /// <summary>
    /// Интерфейс списка
    /// </summary>
    interface IList
    {
        /// <summary>
        /// Добавление элемента в список
        /// </summary>
        /// <param name="data"></param>
        void Add(int data);

        /// <summary>
        /// Удаляет и возвращает элемент с вершины списка
        /// </summary>
        /// <returns></returns>
        int Remove();

        /// <summary>
        /// Находит элемент по введеному значению и удаляет его
        /// </summary>
        /// <param name="data"></param>
        void RemoveElement(int data);

        /// <summary>
        /// Возвращает true если список пуст
        /// </summary>
        /// <returns></returns>
        bool IsEmpty();
    }
}
