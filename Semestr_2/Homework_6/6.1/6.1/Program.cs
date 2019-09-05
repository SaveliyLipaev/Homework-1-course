using System;
using System.Collections.Generic;

namespace _6._1
{
    class Program
    {
        static void Main(string[] args)
        {

            Console.WriteLine(FunctionForTask.Fold(new List<int>() { 1, 2, 3 }, 1, (acc, elem) => acc * elem));

        }
    }
}
