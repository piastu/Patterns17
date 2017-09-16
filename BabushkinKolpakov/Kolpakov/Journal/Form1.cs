using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;
namespace Journal
{
    public partial class Form1 : Form
    {
        public Form1()
        {
            InitializeComponent();
        }
        private void Form1_Load(object sender, EventArgs e)
        {
            ShowAll();
        }
        private void ShowAll()
        {
            Journal.Get.C();
            ShowAuthors();
            ShowPublications();
            Journal.Get.C();
            ShowAuthors();
            ShowPublications();
        }
        private void ShowPublications()
        {
            var pubs = Journal.Get.Publications.Select(id => id).ToList();
            listView1.Items.Clear();
            pubs.ForEach(p =>
            {
                listView1.Items.Add(p.Name);
                var subs = listView1.Items[listView1.Items.Count - 1].SubItems;
                var author = Journal.Get.AuthorPublicationsLinks.Where(apl => apl.Item2 == p && apl.Item3).ToList();
                if (author.Count == 0)
                {
                    var otherAuthors = Journal.Get.AuthorPublicationsLinks.Where(apl => apl.Item2 == p).ToList();
                    if (otherAuthors.Count == 0)
                    {
                        Journal.Get.Publications.Remove(p);
                        Journal.Get.AuthorPublicationsLinks.RemoveWhere(apl => apl.Item2 == p);
                        return;
                    }
                    else
                    {
                        bool first = true;
                        Journal.Get.AuthorPublicationsLinks = Journal.Get.AuthorPublicationsLinks.Select(apl =>
                        {
                            if (first && apl.Item2 == p)
                            {
                                first = false;
                                return Tuple.Create(apl.Item1, apl.Item2, true);
                            }
                            else
                            {
                                return apl;
                            }
                        }).ToHashSet();
                    }
                }
                author = Journal.Get.AuthorPublicationsLinks.Where(apl => apl.Item2 == p && apl.Item3).ToList();
                subs.Add(author[0].Item1.Name);
                subs.Add(p.PageCount.ToString());
                if (p is Monography)
                {
                    subs.Add("Монография");
                    subs.Add("");
                    subs.Add("");
                    subs.Add(((Monography)p).Theme);
                }
                if (p is Book)
                {
                    subs.Add("Книга");
                    subs.Add("");
                    subs.Add(((Book)p).ISBN.ToString());
                    subs.Add("");
                }
                if (p is Article)
                {
                    subs.Add("Статья");
                    subs.Add(((Article)p).ReadersCount.ToString());
                    subs.Add("");
                    subs.Add("");
                }
                subs.Add(p.Date.ToString("dd.MM.yyyy"));
            });
        }
        private void ShowAuthors()
        {
            var authors = Journal.Get.Authors;
            listView2.Items.Clear();
            if(radioButton1.Checked)
                authors.Sort((a, b) => b.HIndex.CompareTo(a.HIndex));
            else
                authors.Sort((a, b) => b.PublicationsCount.CompareTo(a.PublicationsCount));
            authors.ForEach(a =>
            {
                listView2.Items.Add(a.Name);
                var subs = listView2.Items[listView2.Items.Count - 1].SubItems;
                subs.Add((DateTime.Now.Year - a.BirthYear).ToString());
                subs.Add(a.Position);
                subs.Add(a.HIndex.ToString());
                subs.Add(a.PublicationsCount.ToString());
            });
        }
        private void сохранитьToolStripMenuItem_Click(object sender, EventArgs e)
        {
            if (saveFileDialog1.ShowDialog() == DialogResult.OK)
            {
                Journal.Get.Save(saveFileDialog1.FileName);
            }
        }
        private void открытьToolStripMenuItem_Click(object sender, EventArgs e)
        {
            if (openFileDialog1.ShowDialog() == DialogResult.OK)
            {
                Journal.Get.Load(openFileDialog1.FileName);
            }
            ShowAll();
        }
        private void button1_Click(object sender, EventArgs e)
        {
            Author na = new Author();
            var res = Ref<bool>.__(true);
            new AuthorForm(na, res).ShowDialog();
            if(res._)
                Journal.Get.Authors.Add(na);
            ShowAll();
        }
        private void button2_Click(object sender, EventArgs e)
        {
            if (listView2.SelectedIndices.Count == 0)
                return;
            Journal.Get.RemoveAuthor(listView2.SelectedIndices[0]);
            ShowAll();
        }
        private void button3_Click(object sender, EventArgs e)
        {
            if (listView2.SelectedIndices.Count == 0)
                return;
            var res = Ref<bool>.__(false);
            new AuthorForm(Journal.Get.Authors[listView2.SelectedIndices[0]], res).ShowDialog();
            ShowAll();
        }
        private void button6_Click(object sender, EventArgs e)
        {
            new PublicationForm(null, true).ShowDialog();
            ShowAll();
        }
        private void button5_Click(object sender, EventArgs e)
        {
            if (listView1.SelectedIndices.Count == 0)
                return;
            Journal.Get.RemovePublication(listView1.SelectedIndices[0]);
            ShowAll();
        }
        private void button4_Click(object sender, EventArgs e)
        {
            if (listView1.SelectedIndices.Count == 0)
                return;
            new PublicationForm(Journal.Get.Publications[listView1.SelectedIndices[0]], false).ShowDialog();
            ShowAll();
        }
        private void radioButton2_CheckedChanged(object sender, EventArgs e)
        {
            ShowAll();
        }
        private void radioButton1_CheckedChanged(object sender, EventArgs e)
        {
            ShowAll();
        }
    }
}
