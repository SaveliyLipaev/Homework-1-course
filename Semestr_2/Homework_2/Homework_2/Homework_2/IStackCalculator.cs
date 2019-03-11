using System;

namespace Homework_2
{
    interface IStackCalculator
    {
        /// <summary>
        /// Из введеного набора чисел и операторов в постфиксной форме через пробел, производит вычисление
        /// </summary>
        /// <param name="expression"> набора чисел и операторов в постфиксной форме через пробел</param>
        /// <returns>вычисленное значение</returns>
        int DoCalculation(string expression);
    }
}
