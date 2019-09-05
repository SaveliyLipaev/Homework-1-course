using System;
using System.Collections;
using System.Collections.Generic;
using System.Linq;

namespace List
{
    /// <summary>
    /// Класс реализующий интерфейс IList
    /// </summary>
    public class MyList<T> : IList<T> 
    {
        private Node head;
        private Node tail;

        /// <summary>
        /// Свойство отвечающее за колличество эллементов в List
        /// </summary>
        public int Count { get; private set; }

        /// <summary>
        ///Возвращает или задает элемент по указанному индексу
        /// </summary>
        public T this[int index] { get => TakeNodeIndex(index).Data; set => TakeNodeIndex(index).Data = this[index]; }

        /// <summary>
        ///Получает значение, указывающее, является ли объект IList доступным только для чтения.
        /// </summary>
        public bool IsReadOnly => false;

        private class Node
        {
            public Node Next { get; set; }
            public T Data { get; set; }

            public Node(Node next, T data)
            {
                Next = next;
                Data = data;
            }
        }

        /// <summary>
        /// Возвращает адрес Нода по данному индексу
        /// </summary>
        private Node TakeNodeIndex(int index)
        {
            if (ThisBadIndex(index))
            {
                throw new IndexOutOfRangeException();
            }

            Node buffer = head;

            for (var i = 0; i < index; ++i)
            {
                buffer = buffer.Next;
            }

            return buffer;
        }

        private bool ThisBadIndex(int index) => index < 0 || index >= Count;

        /// <summary>
        /// Добавляет эллемент в коллекцию
        /// </summary>
        public void Add(T item)
        {
            if (head == null)
            {
                head = new Node(null, item);
                tail = head;
            }
            else
            {
                tail.Next = new Node(null, item);
                tail = tail.Next;
            }

            ++Count;
        }

        /// <summary>
        /// Удаляет все элементы из коллекции
        /// </summary>
        public void Clear()
        {
            head = null;
            tail = null;
            Count = 0;
        }

        /// <summary>
        /// Определяет, содержит ли коллекция указаное значение
        /// </summary>
        public bool Contains(T item)
        {
            var temp = head;
            while (temp != null)
            {
                if (temp.Data.Equals(item)) 
                {
                    return true;
                }
                temp = temp.Next;
            }
            return false;
        }

        /// <summary>
        /// Копирует элементы коллекции ICollection в массив Array, начиная с указанного индекса массива
        /// </summary>
        public void CopyTo(T[] array, int arrayIndex)
        {
            if (arrayIndex < 0 || arrayIndex >= array.Count()) 
            {
                throw new ArgumentOutOfRangeException();
            }

            if (Count > array.Count() - arrayIndex)
            {
                throw new ArgumentException();
            }

            var buffer = head;

            while (buffer != null)
            {
                array[arrayIndex] = buffer.Data;
                buffer = buffer.Next;
                ++arrayIndex;
            }
        }

        /// <summary>
        /// Определяет индекс заданного элемента в списке
        /// </summary>
        public int IndexOf(T item)
        {
            var buffer = head;
            for (var index = 0; buffer != null; ++index) 
            {
                if (buffer.Data.Equals(item))
                {
                    return index;
                }
                buffer = buffer.Next;
            }

            return -1;
        }

        /// <summary>
        /// Вставляет элемент в список по указанному индексу
        /// </summary>
        public void Insert(int index, T item)
        {
            if (index < 0 || index >= Count + 1) 
            {
                throw new ArgumentOutOfRangeException();
            }
            if (index == 0)
            {
                head = new Node(head, item);
            }
            else if (index == Count) 
            {
                tail.Next = new Node(null, item);
                tail = tail.Next;
            }
            else
            {
                var buffer = head;
                for (var i = 0; i < index - 1; ++i)
                {
                    buffer = buffer.Next;
                }
                buffer.Next = new Node(buffer.Next, item);
            }

            ++Count;
        }

        /// <summary>
        /// Удаляет первое вхождение указанного обьекта из коллекции
        /// </summary>
        public bool Remove(T item)
        {
            if (head == null)
            {
                return false;
            }

            if (EqualityComparer<T>.Default.Equals(head.Data, item))
            {
                head = head.Next;
                --Count;
                return true;
            }
            else 
            {
                var buffer = head;
                while (buffer.Next != null)
                {
                    if (EqualityComparer<T>.Default.Equals(buffer.Next.Data, item))
                    {
                        if (tail == buffer.Next)
                        {
                            tail = buffer;
                        }
                        buffer.Next = buffer.Next.Next;
                        --Count;
                        return true;
                    }
                    buffer = buffer.Next;
                }
            }
            return false;
        }

        /// <summary>
        /// Удаляет элемент, расположенный по указанному индексу
        /// </summary>
        /// <param name="index"></param>
        public void RemoveAt(int index)
        {
            if (ThisBadIndex(index))
            {
                throw new ArgumentOutOfRangeException();
            }
            if (index == 0)
            {
                head = head.Next;
            }
            else
            {
                var buffer = head;
                for (var i = 0; i < index - 1; i++)
                {
                    buffer = buffer.Next;
                }

                if (index == Count - 1)
                {
                    tail = buffer;
                }

                buffer.Next = buffer.Next.Next;
            }
            --Count;
        }

        public IEnumerator<T> GetEnumerator()
        {
            Node current = head;
            while (current != null)
            {
                yield return current.Data;
                current = current.Next;
            }
        }

        IEnumerator IEnumerable.GetEnumerator() => GetEnumerator();
    }
}
