namespace Calculator
{
    partial class FormCalculator
    {
        /// <summary>
        /// Обязательная переменная конструктора.
        /// </summary>
        private System.ComponentModel.IContainer components = null;

        /// <summary>
        /// Освободить все используемые ресурсы.
        /// </summary>
        /// <param name="disposing">истинно, если управляемый ресурс должен быть удален; иначе ложно.</param>
        protected override void Dispose(bool disposing)
        {
            if (disposing && (components != null))
            {
                components.Dispose();
            }
            base.Dispose(disposing);
        }

        #region Код, автоматически созданный конструктором форм Windows

        /// <summary>
        /// Требуемый метод для поддержки конструктора — не изменяйте 
        /// содержимое этого метода с помощью редактора кода.
        /// </summary>
        private void InitializeComponent()
        {
            this.result = new System.Windows.Forms.TextBox();
            this.buttonNumber1 = new System.Windows.Forms.Button();
            this.buttonNumber2 = new System.Windows.Forms.Button();
            this.buttonNumber9 = new System.Windows.Forms.Button();
            this.buttonNumber8 = new System.Windows.Forms.Button();
            this.buttonNumber7 = new System.Windows.Forms.Button();
            this.buttonNumber4 = new System.Windows.Forms.Button();
            this.buttonNumber3 = new System.Windows.Forms.Button();
            this.buttonNumber5 = new System.Windows.Forms.Button();
            this.buttonNumber6 = new System.Windows.Forms.Button();
            this.buttonNumber0 = new System.Windows.Forms.Button();
            this.buttonEqualSign = new System.Windows.Forms.Button();
            this.buttonDeleteSign = new System.Windows.Forms.Button();
            this.buttonClear = new System.Windows.Forms.Button();
            this.buttonDivisionSign = new System.Windows.Forms.Button();
            this.buttonAdditionSign = new System.Windows.Forms.Button();
            this.buttonMultiplicationSign = new System.Windows.Forms.Button();
            this.buttonDifferenceSign = new System.Windows.Forms.Button();
            this.buttonPoint = new System.Windows.Forms.Button();
            this.buttonRightBracket = new System.Windows.Forms.Button();
            this.buttonLeftBracket = new System.Windows.Forms.Button();
            this.SuspendLayout();
            // 
            // result
            // 
            this.result.Anchor = ((System.Windows.Forms.AnchorStyles)(((System.Windows.Forms.AnchorStyles.Top | System.Windows.Forms.AnchorStyles.Left) 
            | System.Windows.Forms.AnchorStyles.Right)));
            this.result.Cursor = System.Windows.Forms.Cursors.Default;
            this.result.Font = new System.Drawing.Font("Microsoft YaHei Light", 16.2F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(204)));
            this.result.Location = new System.Drawing.Point(15, 12);
            this.result.Name = "result";
            this.result.ReadOnly = true;
            this.result.ScrollBars = System.Windows.Forms.ScrollBars.Vertical;
            this.result.Size = new System.Drawing.Size(289, 43);
            this.result.TabIndex = 0;
            this.result.TabStop = false;
            this.result.Text = "0";
            this.result.TextAlign = System.Windows.Forms.HorizontalAlignment.Right;
            // 
            // buttonNumber1
            // 
            this.buttonNumber1.FlatStyle = System.Windows.Forms.FlatStyle.System;
            this.buttonNumber1.Font = new System.Drawing.Font("Microsoft Tai Le", 10.8F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.buttonNumber1.Location = new System.Drawing.Point(15, 67);
            this.buttonNumber1.Name = "buttonNumber1";
            this.buttonNumber1.Size = new System.Drawing.Size(55, 55);
            this.buttonNumber1.TabIndex = 1;
            this.buttonNumber1.Text = "1";
            this.buttonNumber1.UseVisualStyleBackColor = true;
            this.buttonNumber1.Click += new System.EventHandler(this.ButtonClickNumber);
            // 
            // buttonNumber2
            // 
            this.buttonNumber2.FlatStyle = System.Windows.Forms.FlatStyle.System;
            this.buttonNumber2.Font = new System.Drawing.Font("Microsoft Tai Le", 10.8F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.buttonNumber2.Location = new System.Drawing.Point(71, 67);
            this.buttonNumber2.Name = "buttonNumber2";
            this.buttonNumber2.Size = new System.Drawing.Size(55, 55);
            this.buttonNumber2.TabIndex = 4;
            this.buttonNumber2.Text = "2";
            this.buttonNumber2.UseVisualStyleBackColor = true;
            this.buttonNumber2.Click += new System.EventHandler(this.ButtonClickNumber);
            // 
            // buttonNumber9
            // 
            this.buttonNumber9.FlatStyle = System.Windows.Forms.FlatStyle.System;
            this.buttonNumber9.Font = new System.Drawing.Font("Microsoft Tai Le", 10.8F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.buttonNumber9.Location = new System.Drawing.Point(127, 179);
            this.buttonNumber9.Name = "buttonNumber9";
            this.buttonNumber9.Size = new System.Drawing.Size(55, 55);
            this.buttonNumber9.TabIndex = 5;
            this.buttonNumber9.Text = "9";
            this.buttonNumber9.UseVisualStyleBackColor = true;
            this.buttonNumber9.Click += new System.EventHandler(this.ButtonClickNumber);
            // 
            // buttonNumber8
            // 
            this.buttonNumber8.FlatStyle = System.Windows.Forms.FlatStyle.System;
            this.buttonNumber8.Font = new System.Drawing.Font("Microsoft Tai Le", 10.8F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.buttonNumber8.Location = new System.Drawing.Point(71, 179);
            this.buttonNumber8.Name = "buttonNumber8";
            this.buttonNumber8.Size = new System.Drawing.Size(55, 55);
            this.buttonNumber8.TabIndex = 6;
            this.buttonNumber8.Text = "8";
            this.buttonNumber8.UseVisualStyleBackColor = true;
            this.buttonNumber8.Click += new System.EventHandler(this.ButtonClickNumber);
            // 
            // buttonNumber7
            // 
            this.buttonNumber7.FlatStyle = System.Windows.Forms.FlatStyle.System;
            this.buttonNumber7.Font = new System.Drawing.Font("Microsoft Tai Le", 10.8F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.buttonNumber7.Location = new System.Drawing.Point(15, 179);
            this.buttonNumber7.Name = "buttonNumber7";
            this.buttonNumber7.Size = new System.Drawing.Size(55, 55);
            this.buttonNumber7.TabIndex = 7;
            this.buttonNumber7.Text = "7";
            this.buttonNumber7.UseVisualStyleBackColor = true;
            this.buttonNumber7.Click += new System.EventHandler(this.ButtonClickNumber);
            // 
            // buttonNumber4
            // 
            this.buttonNumber4.FlatStyle = System.Windows.Forms.FlatStyle.System;
            this.buttonNumber4.Font = new System.Drawing.Font("Microsoft Tai Le", 10.8F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.buttonNumber4.Location = new System.Drawing.Point(15, 123);
            this.buttonNumber4.Name = "buttonNumber4";
            this.buttonNumber4.Size = new System.Drawing.Size(55, 55);
            this.buttonNumber4.TabIndex = 8;
            this.buttonNumber4.Text = "4";
            this.buttonNumber4.UseVisualStyleBackColor = true;
            this.buttonNumber4.Click += new System.EventHandler(this.ButtonClickNumber);
            // 
            // buttonNumber3
            // 
            this.buttonNumber3.FlatStyle = System.Windows.Forms.FlatStyle.System;
            this.buttonNumber3.Font = new System.Drawing.Font("Microsoft Tai Le", 10.8F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.buttonNumber3.Location = new System.Drawing.Point(127, 67);
            this.buttonNumber3.Name = "buttonNumber3";
            this.buttonNumber3.Size = new System.Drawing.Size(55, 55);
            this.buttonNumber3.TabIndex = 9;
            this.buttonNumber3.Text = "3";
            this.buttonNumber3.UseVisualStyleBackColor = true;
            this.buttonNumber3.Click += new System.EventHandler(this.ButtonClickNumber);
            // 
            // buttonNumber5
            // 
            this.buttonNumber5.FlatStyle = System.Windows.Forms.FlatStyle.System;
            this.buttonNumber5.Font = new System.Drawing.Font("Microsoft Tai Le", 10.8F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.buttonNumber5.Location = new System.Drawing.Point(71, 123);
            this.buttonNumber5.Name = "buttonNumber5";
            this.buttonNumber5.Size = new System.Drawing.Size(55, 55);
            this.buttonNumber5.TabIndex = 10;
            this.buttonNumber5.Text = "5";
            this.buttonNumber5.UseVisualStyleBackColor = true;
            this.buttonNumber5.Click += new System.EventHandler(this.ButtonClickNumber);
            // 
            // buttonNumber6
            // 
            this.buttonNumber6.FlatStyle = System.Windows.Forms.FlatStyle.System;
            this.buttonNumber6.Font = new System.Drawing.Font("Microsoft Tai Le", 10.8F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.buttonNumber6.Location = new System.Drawing.Point(127, 123);
            this.buttonNumber6.Name = "buttonNumber6";
            this.buttonNumber6.Size = new System.Drawing.Size(55, 55);
            this.buttonNumber6.TabIndex = 11;
            this.buttonNumber6.Text = "6";
            this.buttonNumber6.UseVisualStyleBackColor = true;
            this.buttonNumber6.Click += new System.EventHandler(this.ButtonClickNumber);
            // 
            // buttonNumber0
            // 
            this.buttonNumber0.FlatStyle = System.Windows.Forms.FlatStyle.System;
            this.buttonNumber0.Font = new System.Drawing.Font("Microsoft Tai Le", 10.8F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.buttonNumber0.Location = new System.Drawing.Point(71, 237);
            this.buttonNumber0.Name = "buttonNumber0";
            this.buttonNumber0.Size = new System.Drawing.Size(55, 55);
            this.buttonNumber0.TabIndex = 12;
            this.buttonNumber0.Text = "0";
            this.buttonNumber0.UseVisualStyleBackColor = true;
            this.buttonNumber0.Click += new System.EventHandler(this.ButtonClickNumber);
            // 
            // buttonEqualSign
            // 
            this.buttonEqualSign.FlatStyle = System.Windows.Forms.FlatStyle.System;
            this.buttonEqualSign.Font = new System.Drawing.Font("Microsoft Tai Le", 10.8F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.buttonEqualSign.Location = new System.Drawing.Point(127, 237);
            this.buttonEqualSign.Name = "buttonEqualSign";
            this.buttonEqualSign.Size = new System.Drawing.Size(55, 55);
            this.buttonEqualSign.TabIndex = 14;
            this.buttonEqualSign.Text = "=";
            this.buttonEqualSign.UseVisualStyleBackColor = true;
            this.buttonEqualSign.Click += new System.EventHandler(this.ButtonTakeResult);
            // 
            // buttonDeleteSign
            // 
            this.buttonDeleteSign.FlatStyle = System.Windows.Forms.FlatStyle.System;
            this.buttonDeleteSign.Font = new System.Drawing.Font("Microsoft Tai Le", 10.8F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.buttonDeleteSign.Location = new System.Drawing.Point(249, 67);
            this.buttonDeleteSign.Name = "buttonDeleteSign";
            this.buttonDeleteSign.Size = new System.Drawing.Size(55, 55);
            this.buttonDeleteSign.TabIndex = 15;
            this.buttonDeleteSign.Text = "<-";
            this.buttonDeleteSign.UseVisualStyleBackColor = true;
            this.buttonDeleteSign.Click += new System.EventHandler(this.ButtonClickDeleteLastElement);
            // 
            // buttonClear
            // 
            this.buttonClear.FlatStyle = System.Windows.Forms.FlatStyle.System;
            this.buttonClear.Font = new System.Drawing.Font("Microsoft Tai Le", 10.8F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.buttonClear.Location = new System.Drawing.Point(249, 123);
            this.buttonClear.Name = "buttonClear";
            this.buttonClear.Size = new System.Drawing.Size(55, 55);
            this.buttonClear.TabIndex = 17;
            this.buttonClear.Text = "Clear";
            this.buttonClear.UseVisualStyleBackColor = true;
            this.buttonClear.Click += new System.EventHandler(this.ButtonDeleteAll);
            // 
            // buttonDivisionSign
            // 
            this.buttonDivisionSign.FlatStyle = System.Windows.Forms.FlatStyle.System;
            this.buttonDivisionSign.Font = new System.Drawing.Font("Microsoft Tai Le", 10.8F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.buttonDivisionSign.Location = new System.Drawing.Point(188, 67);
            this.buttonDivisionSign.Name = "buttonDivisionSign";
            this.buttonDivisionSign.Size = new System.Drawing.Size(55, 55);
            this.buttonDivisionSign.TabIndex = 18;
            this.buttonDivisionSign.Text = "/";
            this.buttonDivisionSign.UseVisualStyleBackColor = true;
            this.buttonDivisionSign.Click += new System.EventHandler(this.ButtonClickOperator);
            // 
            // buttonAdditionSign
            // 
            this.buttonAdditionSign.FlatStyle = System.Windows.Forms.FlatStyle.System;
            this.buttonAdditionSign.Font = new System.Drawing.Font("Microsoft Tai Le", 10.8F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.buttonAdditionSign.Location = new System.Drawing.Point(249, 179);
            this.buttonAdditionSign.Name = "buttonAdditionSign";
            this.buttonAdditionSign.Size = new System.Drawing.Size(55, 55);
            this.buttonAdditionSign.TabIndex = 19;
            this.buttonAdditionSign.Text = "+";
            this.buttonAdditionSign.UseVisualStyleBackColor = true;
            this.buttonAdditionSign.Click += new System.EventHandler(this.ButtonClickOperator);
            // 
            // buttonMultiplicationSign
            // 
            this.buttonMultiplicationSign.FlatStyle = System.Windows.Forms.FlatStyle.System;
            this.buttonMultiplicationSign.Font = new System.Drawing.Font("Microsoft Tai Le", 10.8F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.buttonMultiplicationSign.Location = new System.Drawing.Point(188, 123);
            this.buttonMultiplicationSign.Name = "buttonMultiplicationSign";
            this.buttonMultiplicationSign.Size = new System.Drawing.Size(55, 55);
            this.buttonMultiplicationSign.TabIndex = 20;
            this.buttonMultiplicationSign.Text = "*";
            this.buttonMultiplicationSign.UseVisualStyleBackColor = true;
            this.buttonMultiplicationSign.Click += new System.EventHandler(this.ButtonClickOperator);
            // 
            // buttonDifferenceSign
            // 
            this.buttonDifferenceSign.FlatStyle = System.Windows.Forms.FlatStyle.System;
            this.buttonDifferenceSign.Font = new System.Drawing.Font("Microsoft Tai Le", 10.8F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.buttonDifferenceSign.Location = new System.Drawing.Point(188, 179);
            this.buttonDifferenceSign.Name = "buttonDifferenceSign";
            this.buttonDifferenceSign.Size = new System.Drawing.Size(55, 55);
            this.buttonDifferenceSign.TabIndex = 21;
            this.buttonDifferenceSign.Text = "-";
            this.buttonDifferenceSign.UseVisualStyleBackColor = true;
            this.buttonDifferenceSign.Click += new System.EventHandler(this.ButtonClickOperator);
            // 
            // buttonPoint
            // 
            this.buttonPoint.FlatStyle = System.Windows.Forms.FlatStyle.System;
            this.buttonPoint.Font = new System.Drawing.Font("Microsoft Tai Le", 10.8F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.buttonPoint.Location = new System.Drawing.Point(15, 237);
            this.buttonPoint.Name = "buttonPoint";
            this.buttonPoint.Size = new System.Drawing.Size(55, 55);
            this.buttonPoint.TabIndex = 22;
            this.buttonPoint.Text = ",";
            this.buttonPoint.UseVisualStyleBackColor = true;
            this.buttonPoint.Click += new System.EventHandler(this.ButtonClickNumber);
            // 
            // buttonRightBracket
            // 
            this.buttonRightBracket.FlatStyle = System.Windows.Forms.FlatStyle.System;
            this.buttonRightBracket.Font = new System.Drawing.Font("Microsoft Tai Le", 10.8F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.buttonRightBracket.Location = new System.Drawing.Point(249, 237);
            this.buttonRightBracket.Name = "buttonRightBracket";
            this.buttonRightBracket.Size = new System.Drawing.Size(55, 55);
            this.buttonRightBracket.TabIndex = 23;
            this.buttonRightBracket.Text = ")";
            this.buttonRightBracket.UseVisualStyleBackColor = true;
            this.buttonRightBracket.Click += new System.EventHandler(this.ButtonClickRightBranch);
            // 
            // buttonLeftBracket
            // 
            this.buttonLeftBracket.FlatStyle = System.Windows.Forms.FlatStyle.System;
            this.buttonLeftBracket.Font = new System.Drawing.Font("Microsoft Tai Le", 10.8F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.buttonLeftBracket.Location = new System.Drawing.Point(188, 237);
            this.buttonLeftBracket.Name = "buttonLeftBracket";
            this.buttonLeftBracket.Size = new System.Drawing.Size(55, 55);
            this.buttonLeftBracket.TabIndex = 24;
            this.buttonLeftBracket.Text = "(";
            this.buttonLeftBracket.UseVisualStyleBackColor = true;
            this.buttonLeftBracket.Click += new System.EventHandler(this.ButtonClickLeftBranch);
            // 
            // Form1
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(8F, 16F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.ClientSize = new System.Drawing.Size(319, 299);
            this.Controls.Add(this.buttonLeftBracket);
            this.Controls.Add(this.buttonRightBracket);
            this.Controls.Add(this.buttonPoint);
            this.Controls.Add(this.buttonDifferenceSign);
            this.Controls.Add(this.buttonMultiplicationSign);
            this.Controls.Add(this.buttonAdditionSign);
            this.Controls.Add(this.buttonDivisionSign);
            this.Controls.Add(this.buttonClear);
            this.Controls.Add(this.buttonDeleteSign);
            this.Controls.Add(this.buttonEqualSign);
            this.Controls.Add(this.buttonNumber0);
            this.Controls.Add(this.buttonNumber6);
            this.Controls.Add(this.buttonNumber5);
            this.Controls.Add(this.buttonNumber3);
            this.Controls.Add(this.buttonNumber4);
            this.Controls.Add(this.buttonNumber7);
            this.Controls.Add(this.buttonNumber8);
            this.Controls.Add(this.buttonNumber9);
            this.Controls.Add(this.buttonNumber2);
            this.Controls.Add(this.buttonNumber1);
            this.Controls.Add(this.result);
            this.FormBorderStyle = System.Windows.Forms.FormBorderStyle.FixedDialog;
            this.MaximizeBox = false;
            this.Name = "Form1";
            this.ShowIcon = false;
            this.Text = "Calculator";
            this.ResumeLayout(false);
            this.PerformLayout();

        }

        #endregion

        private System.Windows.Forms.TextBox result;
        private System.Windows.Forms.Button buttonNumber1;
        private System.Windows.Forms.Button buttonNumber2;
        private System.Windows.Forms.Button buttonNumber9;
        private System.Windows.Forms.Button buttonNumber8;
        private System.Windows.Forms.Button buttonNumber7;
        private System.Windows.Forms.Button buttonNumber4;
        private System.Windows.Forms.Button buttonNumber3;
        private System.Windows.Forms.Button buttonNumber5;
        private System.Windows.Forms.Button buttonNumber6;
        private System.Windows.Forms.Button buttonNumber0;
        private System.Windows.Forms.Button buttonEqualSign;
        private System.Windows.Forms.Button buttonDeleteSign;
        private System.Windows.Forms.Button buttonClear;
        private System.Windows.Forms.Button buttonDivisionSign;
        private System.Windows.Forms.Button buttonAdditionSign;
        private System.Windows.Forms.Button buttonMultiplicationSign;
        private System.Windows.Forms.Button buttonDifferenceSign;
        private System.Windows.Forms.Button buttonPoint;
        private System.Windows.Forms.Button buttonRightBracket;
        private System.Windows.Forms.Button buttonLeftBracket;
    }
}

