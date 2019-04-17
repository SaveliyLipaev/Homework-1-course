using System;
using System.Windows.Forms;

namespace Calculator
{
    /// <summary>
    /// Класс реализующий окно калькулятора и его логику
    /// </summary>
    public partial class FormCalculator : Form
    {
        private bool wasPoint = false;
        private bool wasOperator = false;
        private int quantityLeftBracket = 0;
        private int quantityRightBracket = 0;

        public FormCalculator()
        {
            InitializeComponent();
        }

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
        private string ReplaceCharInString(String str, int index, string newSymb) => str.Remove(index, 1).Insert(index, newSymb.ToString());

        /// <summary>
        /// Метод выполняющийся при нажатии цифры на графической форме, если все хорошо, рисует эту цифрув окне result
        /// </summary>
        private void ButtonClickNumber(object sender, EventArgs e)
        {
            Button button = (Button)sender;

            if (button.Text == ",") 
            {
                if (wasPoint || LastInTextOperator(result.Text) || LastInTextBracket(result.Text))  
                {
                    return;
                }
                wasPoint = true;
            }

            if (ThisStandartStr(result.Text) && button.Text != ",") 
            {
                result.Clear();
            }

            result.Text += button.Text;
        }

        /// <summary>
        /// Метод выполняющийся при нажатии оператора на графической форме, если все хорошо распечатывает на окне result оператор
        /// </summary>
        private void ButtonClickOperator(object sender, EventArgs e)
        {
            Button button = (Button)sender;
            if (result.Text[result.Text.Length - 1] == ',' || result.Text[result.Text.Length - 1] == '(') 
            {
                return;
            }
            if (LastInTextOperator(result.Text))
            {
                result.Text = ReplaceCharInString(result.Text, result.Text.Length - 1, button.Text);
            }
            else
            {
                result.Text += button.Text;
                wasPoint = false;
            }
            wasOperator = true;
        }

        /// <summary>
        /// Метод выполняющийся при нажатии левой скобочкой на графической форме, печатает открывающую скобочку
        /// </summary>
        private void ButtonClickLeftBranch(object sender, EventArgs e)
        {
            if (ThisStandartStr(result.Text))
            {
                result.Clear();
                result.Text += "(";
            }
            else if (LastInTextOperator(result.Text) || result.Text[result.Text.Length - 1] == '(') 
            {
                result.Text += "(";
            }
            else
            {
                return;
            }
            wasOperator = false;
            ++quantityLeftBracket;
        }

        /// <summary>
        /// Метод выполняющийся при нажатии правой скобочкой на графической форме, печатает закрывающуюся скобочку
        /// </summary>
        private void ButtonClickRightBranch(object sender, EventArgs e)
        {
            if (quantityLeftBracket <= quantityRightBracket || LastInTextOperator(result.Text)
                || result.Text[result.Text.Length - 1] == ',' || result.Text[result.Text.Length - 1] == '('
                || !wasOperator)  
            {
                return;
            }
            quantityRightBracket++;
            result.Text += ")";
        }

        /// <summary>
        /// Метод выполняющийся при нажатии левой скобочкой на графической форме, удаляет последний символ в строке
        /// </summary>
        private void buttonClickDeleteLastElement(object sender, EventArgs e)
        {
            if (result.Text[result.Text.Length - 1] == ')')
            {
                quantityRightBracket--;
            }
            else if (result.Text[result.Text.Length - 1] == '(')
            {
                quantityLeftBracket--;
            }
            else if (ThisStandartStr(result.Text))
            {
                result.Text = "0";
            }
            result.Text = result.Text.Remove(result.Text.Length - 1);
            if (result.Text == string.Empty)
            {
                result.Text = "0";
            }
        }

        /// <summary>
        /// Метод выполняющийся при нажатии Clear, очищает всю строку
        /// </summary>
        private void buttonDeleteAll(object sender, EventArgs e)
        {
            result.Text = "0";
            wasPoint = false;
            wasOperator = false;
            quantityLeftBracket = 0;
            quantityRightBracket = 0;
        }

        /// <summary>
        /// Метод выполняющийся при нажатии =, распечатывает результат вычисления выражения
        /// </summary>
        private void buttonTakeResult(object sender, EventArgs e)
        {
            try
            {
                result.Text = ResultExpression.Result(result.Text).ToString();
            }
            catch(DivideByZeroException)
            {
                result.Text = "Деление на ноль";
            }
            catch
            {
                result.Text = "Ошибка";
            }
        }

        /// <summary>
        /// Возвращает true если строка является системной
        /// </summary>
        private bool ThisStandartStr(string str) => str == "0" || str == "Ошибка" || str == "Деление на ноль";
    }
}