using System;
using System.Collections.Generic;
using System.Linq;
using System.Threading.Tasks;

namespace fsm
{
    public struct OddsInfo
    {
        public int HorseId;
        public double Odds;
    } 
    public class horsetest
    {
        public const int HORST_COUNT = 6;
        public int[] horseProb = new int[HORST_COUNT];
        public List<OddsInfo> oddsList = new List<OddsInfo>();
        public int winHorseId;

        public Random rand = new Random();
        public void init()
        {
            oddsList.Clear();
            for (int i = 0; i < HORST_COUNT; i++)
            {
                horseProb[i] = rand.Next(1300, 10001);
                //Console.WriteLine("horseId {0} prob {1}", i, horseProb[i]);
                //if (i < 6)
                //{
                //    horseProb[i] = rand.Next(1000, 10001);
                //}
            }

            double sum = horseProb.Sum() * 1.0;
            double a = 0.95;
            for (int i = 0; i < HORST_COUNT; i++)
            {
                var odd = new OddsInfo();
                odd.HorseId = i + 1;
                odd.Odds = (double)((sum * a / horseProb[i]) );
                //Console.WriteLine("horseId {0} prob {1} odds {2}", i, horseProb[i]/(sum * 0.95), odd.Odds);
                //if(odd.Odds >= 100)
                //{
                //    odd.Odds = (odd.Odds / 10) * 10;
                //}

                oddsList.Add(odd);
            }
        }

        public double BetTest1()
        {
            int betId = rand.Next(1, HORST_COUNT + 1);
            double win = 0;
            if(winHorseId == betId)
            {
                win = oddsList.FirstOrDefault(o => o.HorseId == betId).Odds;
               // Console.WriteLine("betId {0} win {1}", betId, win);

            }

            return win;
        }

        public double BetTest2()
        {
            double win = win = oddsList.FirstOrDefault(o => o.HorseId == winHorseId).Odds;
            //Console.WriteLine("betId {0} win {1}", winHorseId, win);
            return win ;
        }

        
        public double BetTest3()
        {
            var query = (from i in oddsList orderby i.Odds ascending select i).ToList();
            int bet1 = query[0].HorseId;
            int bet2 = query[1].HorseId;
            //Console.WriteLine("{0} {1} {2}", query[0].Odds, query[1].Odds, query[2].Odds);
            double win1 =0, win2 = 0;
            if (winHorseId == bet1)
            {
                win1 = oddsList.FirstOrDefault(o => o.HorseId == bet1).Odds;
            }
            if(winHorseId == bet2)
            {
                win2 = oddsList.FirstOrDefault(o => o.HorseId == bet2).Odds;
            }

            return win1 + win2;
        }
        public void end()
        {
            int sum = horseProb.Sum();

            int hit = rand.Next(1, sum + 1);
            for (int i = 0; i < HORST_COUNT; i++)
            {
                hit -= horseProb[i];
                if (hit <= 0)
                {
                    winHorseId = i + 1;
                    break;
                }
            }

        }
    }
}
