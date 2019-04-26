using System;
using System.Collections;
using System.Collections.Generic;

namespace Set
{
    /// <summary>
    /// Класс реализующий интерфейс ISet<>
    /// </summary>
    public class MySet<T> : ISet<T> where T : IComparable<T>
    {
        private Node head;

        /// <summary>
        /// Получает число элементов, содержащихся в множестве
        /// </summary>
        public int Count { get; private set; }

        /// <summary>
        /// Получает значение, указывающее, является ли объект доступным только для чтения
        /// </summary>
        public bool IsReadOnly => false;

        private class Node
        {
            public Node LeftChild { get; set; }
            public Node RightChild { get; set; }
            public T Item { get; set; }
            public Node(T item)
            {
                Item = item;
            }
        }

        /// <summary>
        /// Добавляет элемент в текущий набор и возвращает значение, указывающее, что элемент был добавлен успешно
        /// </summary>
        public bool Add(T item)
        {
            if (head == null)
            {
                head = new Node(item);
                ++Count;
                return true;
            }
            else
            {
                return FindPositionAndAdd(head, item);
            }
        }

        /// <summary>
        /// Находит позицию и добавляет элемент
        /// </summary>
        private bool FindPositionAndAdd(Node node, T item)
        {
            if (item.CompareTo(node.Item) == 0)
            {
                return false;
            }
            if (item.CompareTo(node.Item) > 0)
            {
                if (node.RightChild == null)
                {
                    node.RightChild = new Node(item);
                    ++Count;
                    return true;
                }
                return FindPositionAndAdd(node.RightChild, item);
            }
            else
            {
                if (node.LeftChild == null)
                {
                    node.LeftChild = new Node(item);
                    ++Count;
                    return true;
                }
                return FindPositionAndAdd(node.LeftChild, item);
            }
        }

        /// <summary>
        /// Удаляет все элементы из коллекции
        /// </summary>
        public void Clear()
        {
            head = null;
            Count = 0;
        }

        /// <summary>
        /// Определяет, содержит ли коллекция указанное значение
        /// </summary>
        public bool Contains(T item)
        {
            var temp = head;
            while (true)
            {
                if (temp == null)
                {
                    return false;
                }
                if (item.CompareTo(temp.Item) == 0)
                {
                    return true;
                }
                if (item.CompareTo(temp.Item) > 0)
                {
                    temp = temp.RightChild;
                }
                else
                {
                    temp = temp.LeftChild;
                }
            }
        }

        /// <summary>
        /// Копирует элементы коллекции в массив Array, начиная с указанного индекса массива Array
        /// </summary>
        public void CopyTo(T[] array, int arrayIndex)
        {
            if (arrayIndex < 0 || arrayIndex >= array.Length)
            {
                throw new ArgumentOutOfRangeException();
            }

            if (Count > array.Length - arrayIndex)
            {
                throw new ArgumentException();
            }

            var queue = new Queue<Node>();
            queue.Enqueue(head);

            while (queue.Count > 0)
            {
                var temp = queue.Dequeue();
                array[arrayIndex] = temp.Item;
                ++arrayIndex;

                if (temp.LeftChild != null)
                {
                    queue.Enqueue(temp.LeftChild);
                }

                if (temp.RightChild != null)
                {
                    queue.Enqueue(temp.RightChild);
                }
            }
        }

        /// <summary>
        /// Возвращает true если элемент присутвствует в коллекции
        /// </summary>
        private bool FindNode(Node node, T item)
        {
            if (item.CompareTo(node.Item) == 0)
            {
                return true;
            }
            if (item.CompareTo(node.Item) > 0)
            {
                if (node.RightChild == null)
                {
                    return false;
                }
                return FindNode(node.RightChild, item);
            }
            else
            {
                if (node.LeftChild == null)
                {
                    return false;
                }
                return FindNode(node.LeftChild, item);
            }
        }

        /// <summary>
        /// Удаляет первое вхождение указанного объекта из коллекции
        /// </summary>
        public bool Remove(T item)
        {
            if (head == null)
            {
                return false;
            }

            var countBefore = Count;

            head = DoDeleteNode(head, item);

            if (countBefore == Count)
            {
                return false;
            }
            return true;
        }

        /// <summary>
        /// Собственно сам метод удаления
        /// </summary>
        private Node DoDeleteNode(Node node, T item)
        {
            if (node == null)
            {
                return null;
            }
            else if (item.CompareTo(node.Item) > 0)
            {
                node.RightChild = DoDeleteNode(node.RightChild, item);
            }
            else if (item.CompareTo(node.Item) < 0)
            {
                node.LeftChild = DoDeleteNode(node.LeftChild, item);
            }
            else
            {
                --Count;
                if (node.RightChild == null)
                {
                    return node.LeftChild;
                }
                else
                {
                    var right = node.RightChild;
                    var left = node.LeftChild;
                    var min = node.RightChild;
                    var parentMin = node;

                    while (min.LeftChild != null)
                    {
                        parentMin = min;
                        min = min.LeftChild;
                    }

                    if (node.RightChild == min)
                    {
                        min.LeftChild = left;
                        return min;
                    }
                    else
                    {
                        parentMin.LeftChild = min.RightChild;
                        min.LeftChild = left;
                        min.RightChild = right;
                        return min;
                    }
                }
            }
            return node;
        }

        /// <summary>
        /// Удаляет все элементы указанной коллекции из текущего набора
        /// </summary>
        public void ExceptWith(IEnumerable<T> other)
        {
            foreach (var temp in other)
            {
                Remove(temp);
            }
        }

        /// <summary>
        /// Изменяет текущий набор, чтобы он содержал только элементы, которые также имеются в заданной коллекции
        /// </summary>
        public void IntersectWith(IEnumerable<T> other)
        {
            var newSet = new MySet<T>();
            foreach (var element in other) 
            {
                if (FindNode(head, element))
                {
                    newSet.Add(element);
                }
            }
            head = newSet.head;
            Count = newSet.Count;
            newSet.Clear();
        }

        /// <summary>
        /// Определяет, является ли текущий набор строгим подмножеством заданной коллекции
        /// </summary>
        public bool IsProperSubsetOf(IEnumerable<T> other)
        {
            var tempSet = new MySet<T>();
            foreach (var element in other) 
            {
                tempSet.Add(element);
            }

            foreach (var element in this)
            {
                if (!tempSet.FindNode(tempSet.head, element))
                {
                    tempSet.Clear();
                    return false;
                }
            }

            if (tempSet.Count > Count)
            {
                tempSet.Clear();
                return true;
            }

            tempSet.Clear();
            return false;
        }

        /// <summary>
        /// Определяет, является ли текущий набор строгим надмножеством заданной коллекции
        /// </summary>
        public bool IsProperSupersetOf(IEnumerable<T> other)
        {
            var count = 0;
            foreach (var element in other)
            {
                if (!FindNode(head, element))
                {
                    return false;
                }
                ++count;
            }

            if (count == Count)
            {
                return false;
            }

            return true;
        }

        /// <summary>
        /// Определяет, является ли текущий набор подмножеством заданной коллекции
        /// </summary>
        public bool IsSubsetOf(IEnumerable<T> other)
        {
            var tempSet = new MySet<T>();
            foreach (var element in other)
            {
                tempSet.Add(element);
            }

            foreach (var element in this)
            {
                if (!tempSet.FindNode(tempSet.head, element))
                {
                    tempSet.Clear();
                    return false;
                }
            }

            tempSet.Clear();
            return true;
        }

        /// <summary>
        /// Определяет, является ли текущий набор надмножеством заданной коллекции
        /// </summary>
        public bool IsSupersetOf(IEnumerable<T> other)
        {
            foreach (var element in other)
            {
                if (!FindNode(head, element))
                {
                    return false;
                }
            }

            return true;
        }

        /// <summary>
        /// Определяет, пересекаются ли текущий набор и указанная коллекция
        /// </summary>
        public bool Overlaps(IEnumerable<T> other)
        {
            foreach (var element in other)
            {
                if (FindNode(head, element))
                {
                    return true;
                }
            }

            return false;
        }

        /// <summary>
        /// Определяет, содержат ли текущий набор и указанная коллекция одни и те же элементы
        /// </summary>
        public bool SetEquals(IEnumerable<T> other)
        {
            var countOther = 0;
            foreach (var element in other)
            {
                if (!FindNode(head, element))
                {
                    return false;
                }
                ++countOther;
            }

            if (countOther == Count)
            {
                return true;
            }

            return false;
        }

        /// <summary>
        /// Изменяет текущий набор, чтобы он содержал только элементы, которые имеются либо в текущем наборе, либо в указанной коллекции, но не одновременно в них обоих
        /// </summary>
        public void SymmetricExceptWith(IEnumerable<T> other)
        {
            foreach (var element in other)
            {
                if (FindNode(head, element))
                {
                    Remove(element);
                }
                else
                {
                    Add(element);
                }
            }
        }

        /// <summary>
        /// Изменяет текущий набор так, чтобы он содержал все элементы, которые имеются в текущем наборе, в указанной коллекции либо в них обоих.
        /// </summary>
        public void UnionWith(IEnumerable<T> other)
        {
            foreach (var element in other)
            {
                Add(element);
            }
        }

        void ICollection<T>.Add(T item)
        {
            Add(item);
        }

        IEnumerator IEnumerable.GetEnumerator()
        {
            return GetEnumerator();
        }

        /// <summary>
        /// Возвращает перечислитель, который осуществляет итерацию по коллекции
        /// </summary>
        public IEnumerator<T> GetEnumerator()
        {
            return new SetEnumerator<T>(this);
        }

        /// <summary>
        /// Осуществление перечесления
        /// </summary>
        private class SetEnumerator<T> : IEnumerator<T>
        {
            private T[] mas;
            private int position = -1;

            public SetEnumerator(ISet<T> set)
            {
                mas = new T[set.Count];
                if (set.Count != 0)
                {
                    set.CopyTo(mas, 0);
                }
            }
            public T Current
            {
                get
                {
                    if (position == -1 || position >= mas.Length)
                    {
                        throw new InvalidOperationException();
                    }
                    return mas[position];
                }
            }

            object IEnumerator.Current => Current;

            public void Dispose()
            { }

            public bool MoveNext()
            {
                if (position < mas.Length - 1)
                {
                    position++;
                    return true;
                }

                return false;
            }

            public void Reset()
            {
                position = -1;
            }
        }
    }
}