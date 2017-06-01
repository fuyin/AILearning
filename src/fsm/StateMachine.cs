using System;
using System.Collections.Generic;
using System.Linq;
using System.Threading.Tasks;

namespace fsm
{
    public class StateMachine<Entity>
    {
        private Entity m_Owner;

        private State<Entity> m_oCurrentState;
        private State<Entity> m_oPreviousState;
        private State<Entity> m_oGlobalState;

        public StateMachine(Entity Obj)
        {
            m_Owner = Obj;
            m_oCurrentState = null;
            m_oPreviousState = null;
            m_oGlobalState = null;
        }


        public void SetCurrentState(State<Entity> s)
        {
            m_oCurrentState = s;
        }

        public void SetPreviousState(State<Entity> s)
        {
            m_oPreviousState = s;
        }

        public void SetGlobalState(State<Entity> s)
        {
            m_oGlobalState = s;
        }

        public void Update()
        {
            if(m_oGlobalState != null)
            {
                m_oGlobalState.Excute(m_Owner);
            }

            if(m_oCurrentState!= null)
            {
                m_oCurrentState.Excute(m_Owner);
            }
        }

        public void ChangeState(State<Entity> NewState)
        {
            if(NewState == null)
            {
                return;
            }
            m_oCurrentState.Exit(m_Owner);
            m_oPreviousState = m_oCurrentState;
            m_oCurrentState = NewState;
            m_oCurrentState.Enter(m_Owner);
        }

        public void RevertToPreviousState()
        {
            ChangeState(m_oPreviousState);
        }

        public bool IsInState(State<Entity> s)
        {
            return m_oCurrentState.Equals(s);
        }

        public State<Entity> CurrentState()
        {
            return m_oCurrentState;
        }

        public State<Entity> PreviousState()
        {
            return m_oPreviousState;
        }

        public State<Entity> GlobalState()
        {
            return m_oGlobalState;
        }
    }
}
