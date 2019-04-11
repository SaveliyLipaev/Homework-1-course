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
        private bool FindNode(int data)
        {
            var ptr = head;
            while(ptr != null)
            {
                if (ptr.data == data) 
                {
                    return true;
                }
                ptr = ptr.next;
            }
            return false;
        }

        /// <summary>
        /// Добавление элемента в начало списка, если такой элемент уже есть в списке кидается исключение AttemptAddAnExistingItemException
        /// </summary>
        /// <param name="data"></param>
        public override void Add(int data)
        {
            if (FindNode(data))
            {
                throw new AttemptAddAnExistingItemException("Невозможно добавить элемент в список, он уже существует");
            }

            base.Add(data);
        }
    }
}
