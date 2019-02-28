using System;

namespace Homework_2
{
    class Program
    {
        static void Main(string[] args)
        {
            var hash = new HashTable();

            hash.Add("123");
            hash.Add("1234");
            hash.Add("9876");

            if (hash.Affiliation("123"))
            {
                hash.Remove("1234");
            }

            hash.PrintHashTable();
            Console.ReadKey();
        }
    }
}
