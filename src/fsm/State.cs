using System;
using System.Collections.Generic;
using System.Linq;
using System.Threading.Tasks;

namespace fsm
{
    public interface State<Entity>
    {
        void Enter(Entity e);

        void Excute(Entity e);

        void Exit(Entity e);
    }
}
