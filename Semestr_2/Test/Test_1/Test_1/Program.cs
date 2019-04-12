using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Test_1
{
    class Program
    {
        static void Main(string[] args)
        {
            var que = new PriorityQueue();
            que.Enqueue(1, 10);
            que.Enqueue(2, 20);
            que.Enqueue(3, 19);
            Console.WriteLine(que.Dequeue());
            Console.WriteLine(que.Dequeue());
            Console.WriteLine(que.Dequeue());
        }
    }
}
