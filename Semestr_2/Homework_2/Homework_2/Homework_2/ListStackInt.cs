using System;

namespace Homework_2
{
    public class ListStackInt : IStack
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
            try
            {
                if (this.IsEmpty())
                {
                    throw new NullReferenceException();
                }
            }
            catch
            {
                throw;
            }

            var value = head.Data;
            head = head.Next;
            --size;
            return value;
        }

        public bool IsEmpty() => size == 0;

        public int Size() => size;
    }
}
