using System;

namespace Homework_4._2
{
    /// <summary>
    /// Класс реализующий unique list
    /// </summary>
    public class UniqueList : List
    {
      

        /// <summary>
        /// Добавление элемента в начало списка, если такой элемент уже есть в списке кидается исключение AttemptAddAnExistingItemException
        /// </summary>
        public override void Add(string data)
        {
            if (ExistsNode(data))
            {
                throw new AttemptAddAnExistingItemException("Невозможно добавить элемент в список, он уже существует");
            }

            base.Add(data);
        }

        /// <summary>
        /// Добавление по введеной позиции
        /// </summary>
        public override void AddPosition(int position, string data)
        {
            if (ExistsNode(data))
            {
                throw new AttemptAddAnExistingItemException("Невозможно добавить элемент в список, он уже существует");
            }

            base.AddPosition(position, data);
        }

        /// <summary>
        /// Изменияет значение на заданной позиции, возвращает true если все успешно
        /// </summary>
        public override bool ChangeValue(int position, string value)
        {
            if (ExistsNode(value))
            {
                throw new AttemptAddAnExistingItemException("Невозможно добавить элемент в список, он уже существует");
            }

            return base.ChangeValue(position, value);
        }
    }
}
