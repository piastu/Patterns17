namespace Journal
{
    partial class PublicationForm
    {
        /// <summary>
        /// Required designer variable.
        /// </summary>
        private System.ComponentModel.IContainer components = null;

        /// <summary>
        /// Clean up any resources being used.
        /// </summary>
        /// <param name="disposing">true if managed resources should be disposed; otherwise, false.</param>
        protected override void Dispose(bool disposing)
        {
            if (disposing && (components != null))
            {
                components.Dispose();
            }
            base.Dispose(disposing);
        }

        #region Windows Form Designer generated code

        /// <summary>
        /// Required method for Designer support - do not modify
        /// the contents of this method with the code editor.
        /// </summary>
        private void InitializeComponent()
        {
            this.button1 = new System.Windows.Forms.Button();
            this.nameT = new System.Windows.Forms.TextBox();
            this.dateT = new System.Windows.Forms.MaskedTextBox();
            this.label4 = new System.Windows.Forms.Label();
            this.label3 = new System.Windows.Forms.Label();
            this.label2 = new System.Windows.Forms.Label();
            this.label1 = new System.Windows.Forms.Label();
            this.pagesT = new System.Windows.Forms.TextBox();
            this.label5 = new System.Windows.Forms.Label();
            this.typeT = new System.Windows.Forms.ComboBox();
            this.label6 = new System.Windows.Forms.Label();
            this.varT = new System.Windows.Forms.TextBox();
            this.coauthorT = new System.Windows.Forms.CheckedListBox();
            this.label7 = new System.Windows.Forms.Label();
            this.label8 = new System.Windows.Forms.Label();
            this.authorT = new System.Windows.Forms.ComboBox();
            this.label9 = new System.Windows.Forms.Label();
            this.citatesT = new System.Windows.Forms.CheckedListBox();
            this.SuspendLayout();
            // 
            // button1
            // 
            this.button1.Location = new System.Drawing.Point(117, 433);
            this.button1.Name = "button1";
            this.button1.Size = new System.Drawing.Size(121, 31);
            this.button1.TabIndex = 15;
            this.button1.Text = "Сохранить";
            this.button1.UseVisualStyleBackColor = true;
            this.button1.Click += new System.EventHandler(this.button1_Click);
            // 
            // nameT
            // 
            this.nameT.Location = new System.Drawing.Point(104, 68);
            this.nameT.Name = "nameT";
            this.nameT.Size = new System.Drawing.Size(173, 20);
            this.nameT.TabIndex = 9;
            // 
            // dateT
            // 
            this.dateT.Location = new System.Drawing.Point(16, 142);
            this.dateT.Mask = "00/00/0000";
            this.dateT.Name = "dateT";
            this.dateT.Size = new System.Drawing.Size(159, 20);
            this.dateT.TabIndex = 13;
            this.dateT.ValidatingType = typeof(System.DateTime);
            // 
            // label4
            // 
            this.label4.AutoSize = true;
            this.label4.Font = new System.Drawing.Font("Microsoft Sans Serif", 10F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(204)));
            this.label4.Location = new System.Drawing.Point(216, 104);
            this.label4.Name = "label4";
            this.label4.Size = new System.Drawing.Size(144, 17);
            this.label4.TabIndex = 12;
            this.label4.Text = "Количество страниц";
            // 
            // label3
            // 
            this.label3.AutoSize = true;
            this.label3.Font = new System.Drawing.Font("Microsoft Sans Serif", 10F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(204)));
            this.label3.Location = new System.Drawing.Point(35, 104);
            this.label3.Name = "label3";
            this.label3.Size = new System.Drawing.Size(124, 17);
            this.label3.TabIndex = 11;
            this.label3.Text = "Дата публикации";
            // 
            // label2
            // 
            this.label2.AutoSize = true;
            this.label2.Font = new System.Drawing.Font("Microsoft Sans Serif", 10F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(204)));
            this.label2.Location = new System.Drawing.Point(114, 39);
            this.label2.Name = "label2";
            this.label2.Size = new System.Drawing.Size(154, 17);
            this.label2.TabIndex = 10;
            this.label2.Text = "Название публикации";
            // 
            // label1
            // 
            this.label1.AutoSize = true;
            this.label1.Font = new System.Drawing.Font("Microsoft Sans Serif", 13F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(204)));
            this.label1.Location = new System.Drawing.Point(71, 9);
            this.label1.Name = "label1";
            this.label1.Size = new System.Drawing.Size(254, 22);
            this.label1.TabIndex = 8;
            this.label1.Text = "Редактирование публикации";
            // 
            // pagesT
            // 
            this.pagesT.Location = new System.Drawing.Point(210, 142);
            this.pagesT.Name = "pagesT";
            this.pagesT.Size = new System.Drawing.Size(163, 20);
            this.pagesT.TabIndex = 16;
            // 
            // label5
            // 
            this.label5.AutoSize = true;
            this.label5.Font = new System.Drawing.Font("Microsoft Sans Serif", 10F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(204)));
            this.label5.Location = new System.Drawing.Point(35, 176);
            this.label5.Name = "label5";
            this.label5.Size = new System.Drawing.Size(115, 17);
            this.label5.TabIndex = 17;
            this.label5.Text = "Тип публикации";
            // 
            // typeT
            // 
            this.typeT.FormattingEnabled = true;
            this.typeT.Items.AddRange(new object[] {
            "Статья",
            "Книга",
            "Монография"});
            this.typeT.Location = new System.Drawing.Point(16, 209);
            this.typeT.Name = "typeT";
            this.typeT.Size = new System.Drawing.Size(159, 21);
            this.typeT.TabIndex = 18;
            this.typeT.Text = "Статья";
            this.typeT.SelectedIndexChanged += new System.EventHandler(this.typeT_SelectedIndexChanged);
            // 
            // label6
            // 
            this.label6.AutoSize = true;
            this.label6.Font = new System.Drawing.Font("Microsoft Sans Serif", 10F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(204)));
            this.label6.Location = new System.Drawing.Point(216, 176);
            this.label6.Name = "label6";
            this.label6.Size = new System.Drawing.Size(123, 17);
            this.label6.TabIndex = 19;
            this.label6.Text = "Число читателей";
            // 
            // varT
            // 
            this.varT.Location = new System.Drawing.Point(210, 210);
            this.varT.Name = "varT";
            this.varT.Size = new System.Drawing.Size(163, 20);
            this.varT.TabIndex = 20;
            // 
            // coauthorT
            // 
            this.coauthorT.CheckOnClick = true;
            this.coauthorT.FormattingEnabled = true;
            this.coauthorT.Location = new System.Drawing.Point(12, 333);
            this.coauthorT.Name = "coauthorT";
            this.coauthorT.Size = new System.Drawing.Size(163, 94);
            this.coauthorT.TabIndex = 21;
            // 
            // label7
            // 
            this.label7.AutoSize = true;
            this.label7.Font = new System.Drawing.Font("Microsoft Sans Serif", 10F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(204)));
            this.label7.Location = new System.Drawing.Point(72, 244);
            this.label7.Name = "label7";
            this.label7.Size = new System.Drawing.Size(47, 17);
            this.label7.TabIndex = 22;
            this.label7.Text = "Автор";
            // 
            // label8
            // 
            this.label8.AutoSize = true;
            this.label8.Font = new System.Drawing.Font("Microsoft Sans Serif", 10F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(204)));
            this.label8.Location = new System.Drawing.Point(60, 304);
            this.label8.Name = "label8";
            this.label8.Size = new System.Drawing.Size(73, 17);
            this.label8.TabIndex = 24;
            this.label8.Text = "Соавторы";
            // 
            // authorT
            // 
            this.authorT.FormattingEnabled = true;
            this.authorT.Location = new System.Drawing.Point(15, 277);
            this.authorT.Name = "authorT";
            this.authorT.Size = new System.Drawing.Size(160, 21);
            this.authorT.TabIndex = 25;
            this.authorT.SelectedIndexChanged += new System.EventHandler(this.authorT_SelectedIndexChanged);
            // 
            // label9
            // 
            this.label9.AutoSize = true;
            this.label9.Font = new System.Drawing.Font("Microsoft Sans Serif", 10F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(204)));
            this.label9.Location = new System.Drawing.Point(241, 301);
            this.label9.Name = "label9";
            this.label9.Size = new System.Drawing.Size(97, 17);
            this.label9.TabIndex = 27;
            this.label9.Text = "Цитирование";
            // 
            // citatesT
            // 
            this.citatesT.CheckOnClick = true;
            this.citatesT.FormattingEnabled = true;
            this.citatesT.Location = new System.Drawing.Point(210, 333);
            this.citatesT.Name = "citatesT";
            this.citatesT.Size = new System.Drawing.Size(163, 94);
            this.citatesT.TabIndex = 26;
            // 
            // PublicationForm
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(6F, 13F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.ClientSize = new System.Drawing.Size(385, 485);
            this.Controls.Add(this.label9);
            this.Controls.Add(this.citatesT);
            this.Controls.Add(this.authorT);
            this.Controls.Add(this.label8);
            this.Controls.Add(this.label7);
            this.Controls.Add(this.coauthorT);
            this.Controls.Add(this.varT);
            this.Controls.Add(this.label6);
            this.Controls.Add(this.typeT);
            this.Controls.Add(this.label5);
            this.Controls.Add(this.pagesT);
            this.Controls.Add(this.button1);
            this.Controls.Add(this.nameT);
            this.Controls.Add(this.dateT);
            this.Controls.Add(this.label4);
            this.Controls.Add(this.label3);
            this.Controls.Add(this.label2);
            this.Controls.Add(this.label1);
            this.Name = "PublicationForm";
            this.StartPosition = System.Windows.Forms.FormStartPosition.CenterParent;
            this.Text = "Публикация";
            this.ResumeLayout(false);
            this.PerformLayout();

        }

        #endregion

        private System.Windows.Forms.Button button1;
        private System.Windows.Forms.TextBox nameT;
        private System.Windows.Forms.MaskedTextBox dateT;
        private System.Windows.Forms.Label label4;
        private System.Windows.Forms.Label label3;
        private System.Windows.Forms.Label label2;
        private System.Windows.Forms.Label label1;
        private System.Windows.Forms.TextBox pagesT;
        private System.Windows.Forms.Label label5;
        private System.Windows.Forms.ComboBox typeT;
        private System.Windows.Forms.Label label6;
        private System.Windows.Forms.TextBox varT;
        private System.Windows.Forms.CheckedListBox coauthorT;
        private System.Windows.Forms.Label label7;
        private System.Windows.Forms.Label label8;
        private System.Windows.Forms.ComboBox authorT;
        private System.Windows.Forms.Label label9;
        private System.Windows.Forms.CheckedListBox citatesT;
    }
}