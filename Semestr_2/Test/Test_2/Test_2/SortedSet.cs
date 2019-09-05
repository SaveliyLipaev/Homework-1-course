using System;
using System.Collections.Generic;

namespace Test_2
{
    /// <summary>
    /// АТД отсортированное множество на основе сравнения CompareList
    /// </summary>
    class SortedSet<T>
    {
        private Node head;
        private CompareList<T> compare;

        public SortedSet()
        {
            compare = new CompareList<T>();
        }

        private class Node
        {
            public Node LeftChild { get; set; }
            public Node RightChild { get; set; }
            public List<T> Item { get; set; }
            public Node(List<T> item)
            {
                Item = item;
            }
        }

        /// <summary>
        /// Добавление в SortedSet элемента (списка)
        /// </summary>
        public bool Add(List<T> item)
        {
            if (head == null)
            {
                head = new Node(item);
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
        private bool FindPositionAndAdd(Node node, List<T> item)
        {
            if (compare.Compare(node.Item, item) == 0)
            {
                return false;
            }
            if (compare.Compare(node.Item, item) > 0)
            {
                if (node.RightChild == null)
                {
                    node.RightChild = new Node(item);
                    return true;
                }
                return FindPositionAndAdd(node.RightChild, item);
            }
            else
            {
                if (node.LeftChild == null)
                {
                    node.LeftChild = new Node(item);
                    return true;
                }
                return FindPositionAndAdd(node.LeftChild, item);
            }
        }

        /// <summary>
        /// Печать множества
        /// </summary>
        public void PrintSet()
        {
            if (head != null)
            {
                DoPrintSet(head);
            }
        }

        /// <summary>
        /// Реализация печати
        /// </summary>
        private void DoPrintSet(Node item)
        {
            if (item.RightChild != null)
            {
                DoPrintSet(item.RightChild);
            }

            PrintList(item.Item);

            if (item.LeftChild != null)
            {
                DoPrintSet(item.LeftChild);
            }

        }

        /// <summary>
        /// Печать списка
        /// </summary>
        private void PrintList(List<T> list)
        {
            foreach (var item in list)
            {
                Console.Write($"{item.ToString()} ");
            }

            Console.WriteLine();
        }

    }
}
