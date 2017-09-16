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
    public partial class PublicationForm : Form
    {
        Publication pubb;
        bool isNew;
        public PublicationForm(Publication p, bool isNew)
        {
            InitializeComponent();
            pubb = p;
            this.isNew = isNew;
            Journal.Get.Authors.ForEach(a =>
            {
                authorT.Items.Add(a.Name);
                coauthorT.Items.Add(a.Name);
            });
            Journal.Get.Publications.Where(pub => pub != p).ToList().ForEach(pub => citatesT.Items.Add(pub.Name));
            if (isNew)
            {
                label1.Text = "Добавление публикации";
            }
            else
            {
                label1.Text = "Редактирование публикации";
                nameT.Text = p.Name;
                dateT.Text = p.Date.ToString("dd.MM.yyyy");
                pagesT.Text = p.PageCount.ToString();
                if (p is Monography)
                {
                    label6.Text = "Тема";
                    typeT.SelectedIndex = 2;
                    varT.Text = ((Monography)p).Theme;
                }
                if (p is Book)
                {
                    label6.Text = "Серийный номер";
                    typeT.SelectedIndex = 1;
                    varT.Text = ((Book)p).ISBN.ToString();
                }
                if (p is Article)
                {
                    label6.Text = "Число читателей";
                    typeT.SelectedIndex = 0;
                    varT.Text = ((Article)p).ReadersCount.ToString();
                }
                int i = 0;
                var author = Journal.Get.AuthorPublicationsLinks.Where(apl => apl.Item3 && apl.Item2 == p).ToList()[0].Item1;
                var coauthors = Journal.Get.AuthorPublicationsLinks.Where(apl => apl.Item2 == p && !apl.Item3).Select(apl => apl.Item1);
                Journal.Get.Authors.ForEach(a =>
                {
                    if (a == author)
                    {
                        authorT.SelectedIndex = i;
                    }
                    ++i;
                });
                i = 0;
                Journal.Get.Authors.Where(a => a != author).ToList().ForEach(a =>
                {
                    if (coauthors.Contains(a))
                    {
                        coauthorT.SetItemChecked(i, true);
                    }
                    ++i;
                });
                i = 0;
                Journal.Get.Publications.Where(pub => pub != p).ToList().ForEach(pub =>
                {
                    if (p.Citates.Contains(pub))
                    {
                        citatesT.SetItemChecked(i, true);
                    }
                    ++i;
                });
            }
        }
        private void button1_Click(object sender, EventArgs e)
        {
            if (nameT.Text == "")
            {
                MessageBox.Show("Название не может быть пустым");
                return;
            }
            try
            {
                DateTime.Parse(dateT.Text);
            }
            catch (FormatException ex)
            {
                MessageBox.Show("Неверная дата");
                return;
            }
            if (pagesT.Text == "")
            {
                MessageBox.Show("Количество страниц не может быть пустым");
                return;
            }
            try
            {
                Int32.Parse(pagesT.Text);
            }
            catch (FormatException ex)
            {
                MessageBox.Show("Количество страниц может быть только числом");
                return;
            }
            if (varT.Text == "")
            {
                MessageBox.Show(label6.Text + " не может быть пустым");
                return;
            }
            if (typeT.SelectedIndex != 2)
            {
                try
                {
                    Int32.Parse(varT.Text);
                }
                catch (FormatException ex)
                {
                    MessageBox.Show(label6.Text + " может быть только числом");
                    return;
                }
            }
            if (authorT.Text == "")
            {
                MessageBox.Show("Автор не может быть пустым");
                return;
            }

            if (!isNew)
            {
                Journal.Get.Publications.Remove(pubb);
                Journal.Get.AuthorPublicationsLinks = Journal.Get.AuthorPublicationsLinks.Where(apl => apl.Item2 != pubb).ToHashSet();
            }
            Publication pub = pubb;
            switch (typeT.SelectedIndex)
            {
                case 0:
                    Article a;
                    if (pub == null)
                        a = new Article();
                    else
                        a = (Article)pub;
                    a.ReadersCount = Int32.Parse(varT.Text);
                    pub = a;
                    break;
                case 1:
                    Book b;
                    if (pub == null)
                        b = new Book();
                    else
                        b = (Book)pub;
                    b.ISBN = Int32.Parse(varT.Text);
                    pub = b;
                    break;
                case 2:
                    Monography m;
                    if (pub == null)
                        m = new Monography();
                    else
                        m = (Monography)pub;
                    m.Theme = varT.Text;
                    pub = m;
                    break;
            }
            pub.Name = nameT.Text;
            pub.Date = DateTime.Parse(dateT.Text);
            pub.PageCount = Int32.Parse(pagesT.Text);
            Journal.Get.Publications.Add(pub);
            var author = Journal.Get.Authors[authorT.SelectedIndex];
            var coauthors = new List<Author>();
            var i = 0;
            Journal.Get.Authors.Where(a => a != author).ToList().ForEach(a =>
            {
                if (coauthorT.CheckedIndices.Contains(i))
                {
                    coauthors.Add(a);
                }
                ++i;
            });
            i = 0;
            pub.Citates.Clear();
            Journal.Get.Publications.Where(p => pubb != p).ToList().ForEach(p =>
            {
                if (citatesT.CheckedIndices.Contains(i))
                {
                    pub.Citates.Add(p);
                }
                ++i;
            });
            var links = Journal.Get.AuthorPublicationsLinks;
            links.Add(Tuple.Create(author, pub, true));
            coauthors.ForEach(a =>
            {
                links.Add(Tuple.Create(a, pub, false));
            });
            Close();
        }
        private void authorT_SelectedIndexChanged(object sender, EventArgs e)
        {
            coauthorT.Items.Clear();
            var author = Journal.Get.Authors[authorT.SelectedIndex];
            Journal.Get.Authors.Where(a => a != author).ToList().ForEach(a =>
            {
                coauthorT.Items.Add(a.Name);
            });
        }
        private void typeT_SelectedIndexChanged(object sender, EventArgs e)
        {
            switch (typeT.SelectedIndex)
            {
                case 0:
                    label6.Text = "Число читателей";
                    break;
                case 1:
                    label6.Text = "Серийный номер";
                    break;
                case 2:
                    label6.Text = "Тема";
                    break;
            }
        }
    }
}
