using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Set
{
    class Program
    {
        static void Main(string[] args)
        {
            var set = new MySet<int>();
            var list = new List<int>() { 1, 5, 4, 10, 9 ,0};

            set.Add(1);
            set.Add(5);
            set.Add(4);
            set.Add(9);
            set.Add(10);
            //set.Add(12);
            //set.Add(11);
            set.UnionWith(list);
            foreach (var el in set)
            {
                Console.WriteLine(el);
            }


        }
    }
}
