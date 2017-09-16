using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Windows.Forms;
namespace Journal
{
    public partial class AuthorForm : Form
    {
        Author au;
        Ref<bool> res;
        public AuthorForm(Author a, Ref<bool> isNew)
        {
            InitializeComponent();
            au = a;
            res = isNew;
            if (isNew._)
            {
                label1.Text = "Добавление автора";
            }
            else
            {
                label1.Text = "Редактирование автора";
                textBox1.Text = a.Name;
                maskedTextBox1.Text = a.BirthYear.ToString();
                textBox2.Text = a.Position;
            }
            res._ = false;
        }
        private void button1_Click(object sender, EventArgs e)
        {
            if (textBox1.Text == "")
            {
                MessageBox.Show("Имя не может быть пустым");
                return;
            }
            if (maskedTextBox1.Text == "")
            {
                MessageBox.Show("Год рождения не может быть пустым");
                return;
            }
            res._ = true;
            au.Name = textBox1.Text;
            au.BirthYear = Int32.Parse(maskedTextBox1.Text);
            au.Position = textBox2.Text;
            Close();
        }
    }
}
