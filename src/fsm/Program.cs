using System;
using System.Collections.Generic;
using System.Linq;
using System.Threading.Tasks;

using System.Threading;

namespace fsm
{
    

    public class TNpc
    {
        public StateMachine<TNpc> machine;
        public TNpc()
        {
            machine = new StateMachine<TNpc>(this);
            machine.SetCurrentState(state_Sleep.Instance);
            bIsSafe = true;
            bThreadened = false;
        }
        
        public void Update()
        {
            machine.Update();
        }

        public bool bIsSafe;
        public bool bThreadened;
        public bool IsSafe()
        {
            return bIsSafe == true;
        }

        public void Snore()
        {
            Console.WriteLine("sleep?");
            Thread.Sleep(1000);
        }

        public void RunAway()
        {
            Console.WriteLine("run away...");
            Thread.Sleep(1000);
        }

        public bool IsThreatened()
        {
            return bThreadened == true;
        }

        public void SetThreated()
        {
            bThreadened = true;
        }

    }

    class state_RunAway : Singleton<state_RunAway>, State<TNpc>
    {
        
        public void Exit(TNpc npc)
        {

        }

        public void Enter(TNpc npc)
        {

        }
        public void Excute(TNpc pNpc)
        {
            if(pNpc.IsSafe())
            {
                pNpc.machine.ChangeState(state_Sleep.Instance);
            }
            else
            {
                pNpc.RunAway();
            }
        }
    }

    class state_Sleep : Singleton<state_RunAway>, State<TNpc>
    {
        static state_Sleep state;

        

        public void Exit(TNpc npc)
        {

        }

        public void Enter(TNpc npc)
        {

        }
        public void Excute(TNpc pNpc)
        {
            if(pNpc.IsThreatened() == true)
            {
                pNpc.machine.ChangeState(state_RunAway.Instance);
            }
            else
            {
                pNpc.Snore();
            }
        }
    }


    public class Program
    {
        //public static void Main(string[] args)
        //{
        //    //builder bd = new ThinkBuilder();
        //    //director dir = new director(bd);
        //    //dir.CreateMan();
        //    //Man s = bd.GetMan();
        //    //if(s == null)
        //    //{
        //    //    return;
        //    //}
        //    //s.ShowMan();
        //    //TNpc npc = new TNpc();

        //    //for(int i = 0; i < 20; i ++)
        //    //{
        //    //    npc.bThreadened = !npc.bThreadened;
        //    //    npc.bIsSafe = !npc.bIsSafe;
        //    //    Console.WriteLine("Threadened {0} Safe {1}", npc.bThreadened, npc.bIsSafe);
        //    //    npc.Update();
        //    //}

        //    //horsetest h = new horsetest();
        //    //double win1 = 0, win2 = 0, win3 = 0;
        //    //int count = 1000000;
        //    //for (int i = 0; i < count; i++)
        //    //{
        //    //    h.init();
        //    //    h.end();
        //    //    win1 += h.BetTest1();
        //    //    win2 += h.BetTest2();
        //    //    win3 += h.BetTest3();
        //    //}

        //    //Console.WriteLine("{0} random bet 1 times {1} win {2} ratio {3}", count, count, win1, win1 / count);
        //    //Console.WriteLine("{0} random bet 6 times {1} win {2} ratio {3}", count, count * 6, win2, win2 / (count * 6));
        //    //Console.WriteLine("{0} random bet 2 times {1} win {2} ratio {3}", count, count * 2, win3, win3 / (2*count));

        //    Console.ReadKey();


        //}

       
}
