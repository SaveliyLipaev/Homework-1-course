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

            var newNode = new Node(data, head);
            ++size;

            for (var i = 0; i < position - 2; ++i)
            {
                newNode.next = newNode.next.next;
            }

            var buffer = newNode.next.next;
            newNode.next.next = newNode;
            newNode.next = buffer;

            return true;
        }

        public void Add(int data)
        {
            var newNode = new Node(data, head);
            head = newNode;
            ++size;
        }

        public int Pop()
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

        public int PopPosition(int position)
        {
            if (!GoodPosition(position))
            {
                Console.WriteLine("Ошибка!!!!!");
                return -1;
            }

            if (position == 1)
            {
                return this.Pop();
            }

            var buffer = head;

            for (var i = 0; i < position - 2; ++i)
            {
                buffer = buffer.next;
            }

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

            var buffer = head;

            for (var i = 0; i < position - 1; ++i) 
            {
                buffer = buffer.next;
            }

            buffer.data = value;
            return true;
        }

        public int GetValue(int position)
        {
            if (!GoodPosition(position)) 
            {
                Console.WriteLine("Ошибка!!!");
                return -1;
            }

            var buffer = head;
   
            for (var i = 0; i < position - 1; ++i)
            {
                buffer = buffer.next;
            }

            return buffer.data;
        }
    }
}
