using System;


namespace Homework_2
{
    public class AddlerHashFunction : IHashFunction
    {
        public int HashFunction(string str)
        {
            int s1 = 1;
            int s2 = 0;

            foreach (var symbol in str)
            {
                s1 = (s1 + symbol) % 65521;
                s2 = (s2 + s1) % 65521;
            }
            s2 = (s2 << 16) + s1;
            return s2 < 0 ? -s2 : s2;
        }
    }
}
