using System;

namespace Calculator
{
    public class LogicForm
    {
        private bool wasPoint = false;
        private bool wasOperator = false;
        private int quantityLeftBracket = 0;
        private int quantityRightBracket = 0;

        /// <summary>
        /// Возвращает true если последний символ в строке оператор
        /// </summary>
        private bool LastInTextOperator(string str) => str[str.Length - 1] == '*' || str[str.Length - 1] == '/'
            || str[str.Length - 1] == '-' || str[str.Length - 1] == '+';

        /// <summary>
        /// Возвращает true если последний символ в строке скобка
        /// </summary>
        private bool LastInTextBracket(string str) => str[str.Length - 1] == '(' || str[str.Length - 1] == ')';

        /// <summary>
        /// Заменяет символ под номером index на newSymb
        /// </summary>
        private string ReplaceCharInString(string str, int index, string newSymb) => str.Remove(index, 1).Insert(index, newSymb.ToString());

        /// <summary>
        /// Метод выполняющийся при нажатии цифры на графической форме, если все хорошо, рисует эту цифрув окне result
        /// </summary>
        public string ButtonClickNumber(string result, string symbol)
        {

            if (symbol == ",")
            {
                if (wasPoint || LastInTextOperator(result) || LastInTextBracket(result))
                {
                    return result;
                }
                wasPoint = true;
            }

              if (ThisStandartStr(result) && symbol != ",")
              {
                  result = "";
              }

            result += symbol;

            return result;
        }

        
        /// <summary>
        /// Метод выполняющийся при нажатии оператора на графической форме, если все хорошо распечатывает на окне result оператор
        /// </summary>
        public string ButtonClickOperator(string result, string symbol)
        {
            if (result[result.Length - 1] == ',' || result[result.Length - 1] == '(')
            {
                return result;
            }
            if (LastInTextOperator(result))
            {
                result = ReplaceCharInString(result, result.Length - 1, symbol);
            }
            else
            {
                result += symbol;
                wasPoint = false;
            }
            wasOperator = true;

            return result;
        }

      
        /// <summary>
        /// Метод выполняющийся при нажатии левой скобочкой на графической форме, печатает открывающую скобочку
        /// </summary>
        public string ButtonClickLeftBranch(string result)
        {
            if (ThisStandartStr(result))
            {
                result = "(";
            }
            else if (LastInTextOperator(result) || result[result.Length - 1] == '(')
            {
                result += "(";
            }
            else
            {
                return result;
            }

            wasOperator = false;
            ++quantityLeftBracket;

            return result;
        }

        
        /// <summary>
        /// Метод выполняющийся при нажатии правой скобочкой на графической форме, печатает закрывающуюся скобочку
        /// </summary>
        public string ButtonClickRightBranch(string result)
        {
            if (quantityLeftBracket <= quantityRightBracket || LastInTextOperator(result)
                || result[result.Length - 1] == ',' || result[result.Length - 1] == '('
                || !wasOperator)
            {
                return result;
            }
            quantityRightBracket++;
            result += ")";

            return result;
        }

        /// <summary>
        /// Метод выполняющийся при нажатии левой скобочкой на графической форме, удаляет последний символ в строке
        /// </summary>
        public string ButtonClickDeleteLastElement(string result)
        {
            if (result[result.Length - 1] == ')')
            {
                quantityRightBracket--;
            }
            else if (result[result.Length - 1] == '(')
            {
                quantityLeftBracket--;
            }
            else if (ThisStandartStr(result))
            {
                result = "0";
            }
            result = result.Remove(result.Length - 1);
            if (result == string.Empty)
            {
                result = "0";
            }

            return result;
        }

        /// <summary>
        /// Метод выполняющийся при нажатии Clear, очищает всю строку
        /// </summary>
        public string ButtonDeleteAll()
        {
            wasPoint = false;
            wasOperator = false;
            quantityLeftBracket = 0;
            quantityRightBracket = 0;
            return "0";
        }

        /// <summary>
        /// Метод выполняющийся при нажатии =, распечатывает результат вычисления выражения
        /// </summary>
        public string ButtonTakeResult(string result)
        {
            try
            {
                result = ResultExpression.Result(result).ToString();
            }
            catch (DivideByZeroException)
            {
                result = "Деление на ноль";
            }
            catch
            {
                result = "Ошибка";
            }

            return result;
        }

        /// <summary>
        /// Возвращает true если строка является системной
        /// </summary>

        private bool ThisStandartStr(string str) => str == "0" || str == "Ошибка" || str == "Деление на ноль";
    }
}
