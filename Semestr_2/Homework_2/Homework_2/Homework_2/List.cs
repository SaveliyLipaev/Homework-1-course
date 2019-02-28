using System;

namespace Homework_2
{
    class List
    {
        private class Node
        {
            public string data;
            public Node next;

            public Node(string data, Node next)
            {
                this.data = data;
                this.next = next;
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
            buffer.next = new Node(data, buffer.next.next);

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
                Console.WriteLine("Ошибка, список пуст!!!");
                return null;
            }

            var value = head.data;
            head = head.next;
            --size;
            return value;
        }

        public string RemovePosition(int position)
        {
            if (!GoodPosition(position))
            {
                Console.WriteLine("Ошибка!!!!!");
                return null;
            }

            if (position == 1)
            {
                return this.Remove();
            }

            var buffer = FindNode(position - 1);

            var value = buffer.next.data;
            buffer.next = buffer.next.next;
            --size;

            return value;
        }

        public bool IsEmpty() => size == 0;

        public int Size() => size;

        public bool ChangeValue(int position, string value)
        {
            if (!GoodPosition(position))
            {
                Console.WriteLine("Ошибка!!!");
                return false;
            }

            FindNode(position).data = value;
            return true;
        }

        public string GetValue(int position)
        {
            if (!GoodPosition(position)) 
            {
                Console.WriteLine("Ошибка!!!");
                return null;
            }
 
            return FindNode(position).data;
        }

        private Node FindNode(int position)
        {
            var buffer = head;
            for (var i = 0; i < position - 1; ++i)
            {
                buffer = buffer.next;
            }
            return buffer;
        }

        public int FindPosition(string str)
        {
            var buffer = head;

            for (var i = 1; i <= this.size; ++i)
            {
                if (buffer.data == str) 
                {
                    return i;
                }

                buffer = buffer.next;
            }

            return -1;
        }
        
        public void PrintList()
        {
            var buffer = head;
            while (buffer != null)
            {
                Console.WriteLine(buffer.data);
                buffer = buffer.next;
            }
        }
    }
}