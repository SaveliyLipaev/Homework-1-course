using System;

namespace Homework_4._2
{
    /// <summary>
    /// Класс реализующий список хранящий строки
    /// </summary>
    public class List
    {
        /// <summary>
        /// Класс реализующий элемент в списке
        /// </summary>
        private class Node
        {
            public string Data { get; set; }
            public Node Next { get; set; }

            public Node(string data, Node next)
            {
                Data = data;
                Next = next;
            }
        }

        private int size;
        private Node head;

        /// <summary>
        /// Возвращает true если позиция находится вне диапозона существования
        /// </summary>
        protected bool GoodPosition(int position) => position > 0 && position <= size + 1;

        /// <summary>
        /// Добавление по введеной позиции
        /// </summary>
        public virtual void AddPosition(int position, string data)
        {
            if (!GoodPosition(position))
            {
                throw new IndexOutOfRangeException();
            }

            if (position == 1)
            {
                Add(data);
                return;
            }

            var buffer = FindNode(position - 1);
            buffer.Next = new Node(data, buffer.Next);

            ++size;
        }

        /// <summary>
        /// Добавление в начало списка
        /// </summary>
        public virtual void Add(string data)
        {
            head = new Node(data, head);
            ++size;
        }

        /// <summary>
        /// Удаление первого элемента в списке 
        /// </summary>
        /// <returns></returns>
        public string Remove()
        {
            if (this.IsEmpty())
            {
                throw new InvalidOperationException("Список пуст");
            }

            var value = head.Data;
            head = head.Next;
            --size;

            return value;
        }

        /// <summary>
        /// Удаление по позиции, возвращает удаленное значение
        /// </summary>
        public string RemovePosition(int position)
        {
            if (!GoodPosition(position))
            {
                throw new IndexOutOfRangeException();
            }

            if (position == 1)
            {
                return this.Remove();
            }

            var buffer = FindNode(position - 1);

            var value = buffer.Next.Data;
            buffer.Next = buffer.Next.Next;
            --size;

            return value;
        }

        /// <summary>
        /// Возвращает true если список пуст
        /// </summary>
        public bool IsEmpty() => size == 0;

        /// <summary>
        /// Возвращает размер списка
        /// </summary>
        public int Size() => size;

        /// <summary>
        /// Получение значения по позиции
        /// </summary>
        public string GetValue(int position)
        {
            if (!GoodPosition(position))
            {
                throw new IndexOutOfRangeException();
            }

            return FindNode(position).Data;
        }
        
        /// <summary>
        /// Удаляет элемент если он найден, в противном случае кидает исключение
        /// </summary>
        public void RemoveElement(string data)
        {
            if (head != null && head.Data == data)
            {
                Remove();
                return;
            }

            var element = head;
            var previousElement = head;

            while (element != null)
            {
                if (element.Data == data)
                {
                    previousElement.Next = element.Next;
                    --size;
                    return;
                }
                previousElement = element;
                element = element.Next;
            }

            throw new MissingItemException("Такого элемента не существует в списке");
        }

        /// <summary>
        /// Возвращает Node по заданой позиции
        /// </summary>
        private Node FindNode(int position)
        {
            var buffer = head;
            for (var i = 0; i < position - 1; ++i)
            {
                buffer = buffer.Next;
            }

            return buffer;
        }

        /// <summary>
        /// Функция возвращает возвращает true если элемент найден
        /// </summary>
        public bool ExistsNode(string data)
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
        /// Изменияет значение на заданной позиции, возвращает true если все успешно
        /// </summary>
        public virtual bool ChangeValue(int position, string value)
        {
            if (!GoodPosition(position))
            {
                return false;
            }

            FindNode(position).Data = value;
            return true;
        }
    }
}