using static System.Runtime.InteropServices.JavaScript.JSType;

namespace Form_parameters_parsing.Models
{
    public class CalcData
    {
        public float xnum { get; set; }
        public float ynum { get; set; }
        public string oper { get; set; }

        public float res;
        public bool divByZero = false;
        

        public string resString()
        { return (xnum.ToString() + ' ' + oper + ' ' + ynum.ToString() + " = " + res.ToString()); }

        public float getRes()
        {   
            switch (oper)
            {
                case "+":
                    return xnum + ynum;
                case "-":
                    return xnum + ynum;
                case "*":
                    return xnum * ynum;
                case "/":
                    if (ynum != 0)
                        return xnum / ynum;
                    else
                    {
                        divByZero = true;
                        return -1;
                    }
                default:
                    return -1;

            }
        }

        public float getResModel()
        {
            switch (oper)
            {
                case "+":
                    res = xnum + ynum; break;
                case "-":
                    res = xnum - ynum; break;
                case "*":
                    res = xnum * ynum; break;
                case "/":
                    if (ynum != 0)
                        res = xnum / ynum;
                    else
                    {
                        res = -1;
                        divByZero = true;
                    }
                    break;
                default:
                    res = -1; break;
            }
            return res;
        }


    }
}
