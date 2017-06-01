using System;
using System.Collections.Generic;
using System.Linq;
using System.Threading.Tasks;

namespace fsm
{
    public abstract class Singleton<T> where T : class, new()
    {
        private static T _instance;
        private static readonly object syslock = new object();

        protected Singleton()
        {
        }

        public static T Instance
        {
            get
            {
                if (_instance == null)
                {
                    lock (syslock)
                    {
                        if (_instance == null)
                        {
                            _instance = new T();
                        }
                    }
                }
                return _instance;
            }
        }
    }
}
