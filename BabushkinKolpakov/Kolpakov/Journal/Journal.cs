using System;
using System.Collections.Generic;
using System.Linq;
namespace Journal
{
    class Journal
    {
        public HashSet<Tuple<Author, Publication, bool>> AuthorPublicationsLinks { get; set; }
        public List<Author> Authors { get; set; }
        public List<Publication> Publications { get; set; }
        public static Journal Get = new Journal();
        private Journal()
        {
            AuthorPublicationsLinks = new HashSet<Tuple<Author, Publication, bool>>();
            Authors = new List<Author>();
            Publications = new List<Publication>();
        }
        public void Save(string filename)
        {
            Utils.WriteToBinaryFile(filename, Tuple.Create(Authors, Publications, AuthorPublicationsLinks));
        }

        public void Load(string filename)
        {
            var t = Utils.ReadFromBinaryFile<Tuple<List<Author>, List<Publication>, HashSet<Tuple<Author, Publication, bool>>>>(filename);
            Authors = t.Item1;
            Publications = t.Item2;
            AuthorPublicationsLinks = t.Item3;
        }
        public void RemoveAuthor(int idx)
        {
            var author = Authors[idx];
            Authors.RemoveAt(idx);
            AuthorPublicationsLinks.RemoveWhere(t => t.Item1 == author);
        }
        public void RemovePublication(int idx)
        {
            var pub = Publications[idx];
            Publications.RemoveAt(idx);
            AuthorPublicationsLinks.RemoveWhere(t => t.Item2 == pub);
        }
        private void CountAuthorsPublications()
        {
            var counts = new Dictionary<Author, int>();
            AuthorPublicationsLinks.ToList().ForEach(apl => counts[apl.Item1] = counts.GetValueOrDefault(apl.Item1, 0) + 1);
            counts.ToList().ForEach(ac => ac.Key.PublicationsCount = ac.Value);
        }
        //Вычисление индекса Хирша
        private void CountAuthorsCitateIndex()
        {
            var citatesCount = new Dictionary<Publication, int>();
            Publications.ForEach(p => p.Citates.ForEach(cp => citatesCount[cp] = citatesCount.GetValueOrDefault(cp, 0) + 1));
            Authors.ForEach(a =>
            {
                var aPubs = AuthorPublicationsLinks.Where(apl => apl.Item1 == a).Select(apl => Tuple.Create(apl.Item2, citatesCount.GetValueOrDefault(apl.Item2, 0))).ToList();
                aPubs.Sort((pc1, pc2) => pc2.Item2.CompareTo(pc1.Item2));
                int h = 0;
                while (h < aPubs.Count && h <= aPubs[h].Item2)
                {
                    ++h;
                }
                a.HIndex = h;
            });
        }
        public void C()
        {
            CountAuthorsPublications();
            CountAuthorsCitateIndex();
        }
    }
}
