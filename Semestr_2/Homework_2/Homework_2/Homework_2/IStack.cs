using System;

namespace Homework_2
{
    interface IStack
    {
        /// <summary>
        /// Этот метод добавляет значение в начало списка
        /// </summary>
        /// <param name="data">Значение, передаваемое в список</param>
        void Add(int data);

        /// <summary>
        /// Удаляет и возвращает первую позцицию в списке
        /// </summary>
        /// <returns>Возвращает удаленное значение</returns>
        int Remove();

        /// <summary>
        /// Проверка пустоты списка
        /// </summary>
        /// <returns>Возвращает true если список пуст, иначе false</returns>
        bool IsEmpty();

        /// <summary>
        /// Колличесвто элементов в списке
        /// </summary>
        /// <returns>Возвращает колличесвто элементов в списке</returns>
        int Size();

        /// <summary>
        /// Получает значение по позции
        /// </summary>
        /// <param name="position">Позиция, на которой стоит элемент, значение которого нужно получить</param>
        /// <returns>Возвращает значение на нужной нам позции</returns>
        int GetValue(int position);
    }
}
