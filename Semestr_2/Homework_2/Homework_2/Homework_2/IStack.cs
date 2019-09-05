using System;

namespace Homework_2
{
    /// <summary>
    /// Интерфейс стэка
    /// </summary>
    public interface IStack
    {
        /// <summary>
        /// Этот метод добавляет значение в начало списка
        /// </summary>
        /// <param name="data">Значение, передаваемое в список</param>
        void Push(int data);

        /// <summary>
        /// Удаляет и возвращает первую позцицию в списке
        /// </summary>
        /// <returns>Возвращает удаленное значение</returns>
        int Pop();

        /// <summary>
        /// Проверка пустоты списка
        /// </summary>
        /// <returns>Возвращает true если список пуст, иначе false</returns>
        bool IsEmpty();

        /// <summary>
        /// Колличесвто элементов в списке
        /// </summary>
        /// <returns>Возвращает колличество элементов в списке</returns>
        int Size();
    }
}
