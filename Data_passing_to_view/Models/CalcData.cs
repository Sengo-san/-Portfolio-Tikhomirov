namespace _Data_passing_to_view.Models
{
    public class CalcData
    {
        public int xnum;
        public int ynum;
        public int add;
        public int sub;
        public int mult;
        public int div;
        public bool divByZero;
        private void CreateData()
        {
            Random rnd = new Random();
            xnum = rnd.Next(0, 10);
            ynum = rnd.Next(0, 10);
            //ynum = 0;
            add = xnum + ynum;
            sub = xnum - ynum;
            mult = xnum * ynum;
            if (ynum != 0) {
                div = xnum / ynum;
                divByZero = false;
            }
            else {
                div = 404;
                divByZero = true;
            }
        }
       public CalcData() => CreateData();
    }
}
