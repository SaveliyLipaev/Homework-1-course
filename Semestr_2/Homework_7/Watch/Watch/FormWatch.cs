using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace Watch
{
    /// <summary>
    /// WATCH
    /// </summary>
    public partial class FormWatch : Form
    {
        public FormWatch()
        {
            InitializeComponent();
        }

        /// <summary>
        /// Каждый тик юзается этот метод
        /// </summary>
        private void TimerSecond_Tick(object sender, EventArgs e)
        {
            tablo.Text = DateTime.Now.ToString("T");
        }

        /// <summary>
        /// При запуске формы, запуститься таймер
        /// </summary>
        private void FormWatch_Load(object sender, EventArgs e)
        {
            timerSecond.Start();
        }
    }
}
