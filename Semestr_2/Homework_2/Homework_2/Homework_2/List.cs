using System;

namespace Homework_2
{
    /// <summary>
    /// Класс реализующий список хранящий строки
    /// </summary>
    class ListString
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
        private bool GoodPosition(int position) => position > 0 && position <= size;

        /// <summary>
        /// Добавление по введеной позиции
        /// </summary>
        public void AddPosition(int position, string data)
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
            buffer.Next = new Node(data, buffer.Next.Next);

            ++size;

            return;
        }

        /// <summary>
        /// Добавление в начало списка
        /// </summary>
        public void Add(string data)
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
        /// Изменияет значение на заданной позиции, возвращает true если все успешно
        /// </summary>
        public bool ChangeValue(int position, string value)
        {
            if (!GoodPosition(position))
            {
                return false;
            }

            FindNode(position).Data = value;
            return true;
        }

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
        /// Возвращает позицию по значению
        /// </summary>
        public int FindPosition(string str)
        {
            var buffer = head;

            for (var i = 1; i <= this.size; ++i)
            {
                if (buffer.Data == str) 
                {
                    return i;
                }

                buffer = buffer.Next;
            }
            return -1;
        }
        
        /// <summary>
        /// Распечатывание списка
        /// </summary>
        public void PrintList()
        {
            var buffer = head;
            while (buffer != null)
            {
                Console.WriteLine(buffer.Data);
                buffer = buffer.Next;
            }
        }
    }
}