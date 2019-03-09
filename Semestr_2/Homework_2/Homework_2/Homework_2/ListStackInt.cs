using System;

namespace Homework_2
{
    class ListStackInt : IStack
    {
        private class Node
        {
            public int Data { get; set; }
            public Node Next { get; set; }

            public Node(int data, Node next)
            {
                Data = data;
                Next = next;
            }
        }

        private int size;
        private Node head;

        private bool GoodPosition(int position) => position > 0 && position <= size;

        public void Add(int data)
        {
            head = new Node(data, head);
            ++size;
        }

        public int Remove()
        {
            if (this.IsEmpty())
            {
                Console.WriteLine("Ошибка, список пуст!!!");
                return -1;
            }

            var value = head.Data;
            head = head.Next;
            --size;
            return value;
        }

        public bool IsEmpty() => size == 0;

        public int Size() => size;

        public int GetValue(int position)
        {
            if (!GoodPosition(position))
            {
                Console.WriteLine("Ошибка!!!");
                return -1;
            }

            return FindNode(position).Data;
        }

        private Node FindNode(int position)
        {
            var buffer = head;
            for (var i = 0; i < position - 1; ++i)
            {
                buffer = buffer.Next;
            }
            return buffer;
        }
    }
}
