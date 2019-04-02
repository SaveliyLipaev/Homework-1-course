using System;

namespace Homework_2
{
    public class ArrayStack : IStack
    {
        private int[] nodes;
        private int size;

        public ArrayStack(int initialSize)
        {
            nodes = new int[initialSize];
        }

        public ArrayStack() : this(3)
        { }

        public void Push(int data)
        {
            CheckDimension();
            nodes[size] = data;
            ++size;
        }

        private void CheckDimension()
        {
            if (size == nodes.Length)
            {
                Extension();
            }
        }

        private void Extension()
        {
            var newNodes = new int[nodes.Length * 2 + 1];

            for (var i = 0; i < nodes.Length; ++i)
            {
                newNodes[i] = nodes[i];
            }
            nodes = newNodes;
        }

        public bool IsEmpty() => size == 0;

        public int Pop()
        {
           if (IsEmpty())
           {
               throw new NullReferenceException();
           }

            size--;
            int buffer = nodes[size];
            return buffer;
        }

        public int Size() => size;
    }
}
