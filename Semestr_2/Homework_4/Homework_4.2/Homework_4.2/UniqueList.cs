using System;

namespace Homework_4._2
{
    /// <summary>
    /// Класс реализующий unique list
    /// </summary>
    public class UniqueList : List
    {
        /// <summary>
        /// Функция возвращает возвращает true если элемент найден
        /// </summary>
        private bool FindNode(string data)
        {
            var ptr = head;
            while (ptr != null) 
            {
                if (ptr.Data == data) 
                {
                    return true;
                }
                ptr = ptr.Next;
            }
            return false;
        }

        /// <summary>
        /// Добавление элемента в начало списка, если такой элемент уже есть в списке кидается исключение AttemptAddAnExistingItemException
        /// </summary>
        public override void Add(string data)
        {
            if (FindNode(data))
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
            if (FindNode(data))
            {
                throw new AttemptAddAnExistingItemException("Невозможно добавить элемент в список, он уже существует");
            }

            base.AddPosition(position, data);
        }
    }
}
