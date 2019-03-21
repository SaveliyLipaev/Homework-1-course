using System;

namespace Homework_2
{
    class ListString
    {
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

        private bool GoodPosition(int position) => position > 0 && position <= size;

        public bool AddPosition(int position, string data)
        {
            if (!GoodPosition(position))
            {
                return false;
            }

            if (position == 1)
            {
                Add(data);
                return true;
            }

            var buffer = FindNode(position - 1);
            buffer.Next = new Node(data, buffer.Next.Next);

            ++size;

            return true;
        }

        public void Add(string data)
        {
            head = new Node(data, head);
            ++size;
        }

        public string Remove()
        {
            if (this.IsEmpty())
            {
                throw new NullReferenceException("Стек пуст");
            }

            var value = head.Data;
            head = head.Next;
            --size;
            return value;
        }

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

        public bool IsEmpty() => size == 0;

        public int Size() => size;

        public bool ChangeValue(int position, string value)
        {
            if (!GoodPosition(position))
            {
                return false;
            }

            FindNode(position).Data = value;
            return true;
        }

        public string GetValue(int position)
        {
            if (!GoodPosition(position))
            {
                throw new IndexOutOfRangeException();
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