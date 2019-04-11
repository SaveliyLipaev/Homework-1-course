using System;

namespace Homework_2
{
    /// <summary>
    /// Интерфейс стекового калькулятора
    /// </summary>
    interface IStackCalculator
    {
        /// <summary>
        /// Из введеного набора чисел и операторов в постфиксной форме через пробел, производит вычисление
        /// </summary>
        /// <param name="expression"> набор чисел и операторов в постфиксной форме через пробел</param>
        /// <returns>вычисленное значение</returns>
        int DoCalculation(string expression);
    }
}
