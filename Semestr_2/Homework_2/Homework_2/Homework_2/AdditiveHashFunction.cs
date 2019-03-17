using System;


namespace Homework_2
{
    public class AdditiveHashFunction : IHashFunction
    {
        public int HashFunction(string str)
        {
            int prime = 31;
            int sum = 0;

            for (var i = 0; i < str.Length; ++i)
            {
                sum = sum + str[i] * prime;
                prime *= prime;
            }

            return sum < 0 ? -sum : sum;
        }
    }
}
