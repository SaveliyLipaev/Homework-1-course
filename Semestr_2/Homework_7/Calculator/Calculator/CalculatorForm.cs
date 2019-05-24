using System;
using System.Windows.Forms;

namespace Calculator
{
    /// <summary>
    /// Класс реализующий окно калькулятора и его логику
    /// </summary>
    public partial class FormCalculator : Form
    {
        private LogicForm logicForm;

        public FormCalculator()
        {
            InitializeComponent();
            logicForm = new LogicForm();
        }

        /// <summary>
        /// Метод выполняющийся при нажатии цифры на графической форме, если все хорошо, рисует эту цифрув окне result
        /// </summary>
        private void ButtonClickNumber(object sender, EventArgs e)
        {
            var button = (Button)sender;

            result.Text = logicForm.ButtonClickNumber(result.Text, button.Text);
        }

        /// <summary>
        /// Метод выполняющийся при нажатии оператора на графической форме, если все хорошо распечатывает на окне result оператор
        /// </summary>
        private void ButtonClickOperator(object sender, EventArgs e)
        {
            var button = (Button)sender;

            result.Text = logicForm.ButtonClickOperator(result.Text, button.Text);
        }

        /// <summary>
        /// Метод выполняющийся при нажатии левой скобочкой на графической форме, печатает открывающую скобочку
        /// </summary>
        private void ButtonClickLeftBranch(object sender, EventArgs e)
        {
            result.Text = logicForm.ButtonClickLeftBranch(result.Text);
        }

        /// <summary>
        /// Метод выполняющийся при нажатии правой скобочкой на графической форме, печатает закрывающуюся скобочку
        /// </summary>
        private void ButtonClickRightBranch(object sender, EventArgs e)
        {
            result.Text = logicForm.ButtonClickRightBranch(result.Text);
        }

        /// <summary>
        /// Метод выполняющийся при нажатии левой скобочкой на графической форме, удаляет последний символ в строке
        /// </summary>
        private void ButtonClickDeleteLastElement(object sender, EventArgs e)
        {
            result.Text = logicForm.ButtonClickDeleteLastElement(result.Text);
        }

        /// <summary>
        /// Метод выполняющийся при нажатии Clear, очищает всю строку
        /// </summary>
        private void ButtonDeleteAll(object sender, EventArgs e)
        {
            result.Text = logicForm.ButtonDeleteAll();
        }

        /// <summary>
        /// Метод выполняющийся при нажатии =, распечатывает результат вычисления выражения
        /// </summary>
        private void ButtonTakeResult(object sender, EventArgs e)
        {
            result.Text = logicForm.ButtonTakeResult(result.Text);
        }
    }
}