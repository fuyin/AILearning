using System;
using System.Collections.Generic;
using System.Linq;
using System.Threading.Tasks;

namespace fsm
{
    public enum ManType {
        Fat = 0,
        Think = 1,
    }

    public class Man {
        private ManType m_type;
        public void SetHead(ManType type)
        {
            m_type = type;
        }

        public void SetBody(ManType type)
        {
            m_type = type;
        }

        public void SetHand(ManType type)
        {
            m_type = type;
        }

        public void SetFoot(ManType type)
        {
            m_type = type;
        }

        public void ShowMan()
        {
            switch (m_type)
            {
                case ManType.Fat:
                    Console.WriteLine("Iam fat");
                    break;
                case ManType.Think:
                    Console.WriteLine("Iam think");
                    break;
                default:
                    Console.WriteLine("Iam normal man");
                    break;
            }
        }
    }
    public interface builder
    {
        void BuildHead();
        void BuildBody();

        void BuildHand();

        void BuildFoot();

        Man GetMan();
    }

    public class FatBuilder:builder {
        Man m_Man;
         public FatBuilder()
        {
            m_Man = new Man();
        }

        public void BuildHead()
        {
            m_Man.SetHead(ManType.Fat);
        }

        public void BuildBody()
        {
            m_Man.SetBody(ManType.Fat); 
        }

        public void BuildHand()
        {
            m_Man.SetHand(ManType.Fat);
        }

        public void BuildFoot()
        {
            m_Man.SetFoot(ManType.Fat);
        }

        public Man GetMan()
        {
            return m_Man;
        }
    }

    public class ThinkBuilder:builder
    {
        Man m_Man;

        public ThinkBuilder()
        {
            m_Man = new Man();
        }
        

        public void BuildHead()
        {
            m_Man.SetHead(ManType.Think);
        }

        public void BuildBody()
        {
            m_Man.SetBody(ManType.Think);
        }

        public void BuildHand()
        {
            m_Man.SetHand(ManType.Think);
        }

        public void BuildFoot()
        {
            m_Man.SetFoot(ManType.Think);
        }

        public Man GetMan()
        {
            return m_Man;
        }
    }

    public class director
    {
        public director(builder bd)
        {
            m_bd = bd;
        }

        public void CreateMan()
        {
            m_bd.BuildHead();
            m_bd.BuildBody();
            m_bd.BuildHand();
            m_bd.BuildFoot();
        }

        builder m_bd;
    }
}
  
