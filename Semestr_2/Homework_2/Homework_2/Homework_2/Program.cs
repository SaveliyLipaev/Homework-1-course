using System;

namespace Homework_2
{
    class Program
    {
        static void Main(string[] args)
        {
            var list = new List();
            list.Add(4);
            list.Add(3);
            list.Add(2);
            list.Add(1);
            list.AddPosition(3, 10);
            //list.ChangeValue(3, 99);

            Console.WriteLine(list.GetValue(3));
            Console.ReadKey();
        }
    }
}
