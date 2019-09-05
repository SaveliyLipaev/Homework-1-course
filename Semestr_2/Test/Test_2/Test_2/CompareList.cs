using System.Collections.Generic;

namespace Test_2
{
    /// <summary>
    /// Сравнение двух объектов и возврат значения, указывающего, является ли один объект меньшим, равным или большим другого
    /// </summary>
    public class CompareList<T> : IComparer<List<T>>
    {
        public int Compare(System.Collections.Generic.List<T> x, System.Collections.Generic.List<T> y)
        {
            if (x.Count > y.Count)
            {
                return 1;
            }
            else if (x.Count < y.Count)
            {
                return -1;
            }

            return 0;
        }
    }
}
