using System;

namespace Homework_2
{
    class List
    {
        private class Node
        {
            public int data;
            public Node next;

            public Node(int data, Node next)
            {
                this.data = data;
                this.next = next;
            }
        }

        private int size;
        private Node head;

        private bool GoodPosition(int position) => position > 0 && position <= size;

        public bool AddPosition(int position, int data)
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

            var value = head.data;
            head = head.next;
            --size;
            return value;
        }

        public int RemovePosition(int position)
        {
            if (!GoodPosition(position))
            {
                Console.WriteLine("Ошибка!!!!!");
                return -1;
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

        public bool ChangeValue(int position, int value)
        {
            if (!GoodPosition(position))
            {
                Console.WriteLine("Ошибка!!!");
                return false;
            }

            FindNode(position).data = value;
            return true;
        }

        public int GetValue(int position)
        {
            if (!GoodPosition(position)) 
            {
                Console.WriteLine("Ошибка!!!");
                return -1;
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
    }
}
