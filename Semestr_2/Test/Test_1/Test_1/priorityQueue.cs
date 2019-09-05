using System;

namespace Test_1
{
    /// <summary>
    /// Класс реализующий приоритетную очередь
    /// </summary>
    public class PriorityQueue
    {
        private Node head;

        /// <summary>
        /// Класс реализующий элемент очереди
        /// </summary>
        private class Node
        {
            public Object Data { get; set; }
            public int Priority { get; set; }
            public Node Next { get; set; }

            public Node(Object data, int priority, Node next)
            {
                Data = data;
                Priority = priority;
                Next = next;
            }

        }

        /// <summary>
        /// Принимает значение и численный приоритет, добавляет элемент в очередь
        /// </summary>
        public void Enqueue(Object data, int priority)
        {
            if (isEmpty())
            {
                head = new Node(data, priority, head);
            }
            else if (priority <= head.Priority)
            {
                head = new Node(data, priority, head);
            }
            else
            {
                var buffer = head;
                while (buffer.Next != null)
                {
                    if (buffer.Next.Priority >= priority)
                    {
                        buffer.Next = new Node(data, priority, buffer.Next);
                        return;
                    }
                    buffer = buffer.Next;
                }
                buffer.Next = new Node(data, priority, buffer.Next);
            }
        }

        /// <summary>
        /// Возвращает значение с наивысшим приоритетом и удаляет его из очереди
        /// </summary>
        /// <returns></returns>
        public Object Dequeue()
        {
            if (isEmpty()) 
            {
                throw new EmptyQueueException("Очередь пуста");
            }

            var value = head.Data;

            if (head.Next == null) 
            {
                head = null;
                return value;
            }
            var buffer = head;
            while (buffer.Next.Next != null)
            {
                buffer = buffer.Next;
            }
            value = buffer.Next.Data;
            buffer.Next = null;
            return value;
        }

        /// <summary>
        /// Возвращает true если очередь пуста
        /// </summary>
        public bool isEmpty() => head == null;
    }
}