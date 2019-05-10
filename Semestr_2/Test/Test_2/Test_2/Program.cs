using System.Collections.Generic;

namespace Test_2
{
    class Program
    {
        static void Main(string[] args)
        {
            var masString = new string[] { "1111 2222", "33", "1111 2222 3333 4444", "1111 2222 3333 4444", "1111 2222 33333" };

            var set = ArrayInSet(masString);

            set.PrintSet();
        }

        /// <summary>
        /// Функция возвращающая SortedSet состоящий из входного массива строк
        /// </summary>
        public static SortedSet<string> ArrayInSet(string[] mas)
        {
            var set = new SortedSet<string>();

            foreach (var item in mas)
            {
                var tempArray = item.Split(' ');
                var list = new List<string>();

                foreach (var tempItem in tempArray)
                {
                    list.Add(tempItem);
                }

                set.Add(list);
            }

            return set;
        }
    }
}