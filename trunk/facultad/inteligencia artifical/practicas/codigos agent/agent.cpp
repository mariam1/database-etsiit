#include "agent.h"
#include "environment.h"
#include <cstdlib>
#include <iostream>
#include <iomanip>
using namespace std;

// -----------------------------------------------------------
Agent::ActionType Agent::Think()
{
    /*for(int i = 0; i<20; i++)
			for(int j = 0; j<20; j++)
				MAPA[i][j] = '-';
		for(int i = 0; i<2000; i++)
			ACT[i] = 'N';
		ACT[0] = 'I';
		for(int i = 0; i<10000; i++) etapACT[i] = 'I';
		for(int i = 0; i<4000; i++) posicion[i] = 0;
		*/
    if(etapa == 1)
    {
        if(bump_)
        {
            MAPA[x][y] = 'W';
            if(estado == "UP") x = x+1;
            else if(estado == "DOWN") x = x-1;
            else if(estado == "RIGHT") y = y-1;
            else if(estado == "LEFT") y = y+1;
            registro("VOLVER");
            if (dirty_) return actSUCK;
            else return actIDLE;
        }
        if (dirty_) return actSUCK;
        if(MAPA[x-1][y] == '-')
        {
            estado = Up();
            registro("UP");
        }

        else if(MAPA[x][y-1] == '-')
        {
            estado = Left();
            registro("LEFT");
        }
        else if(MAPA[x][y+1] == '-')
        {
            estado = Right();
            registro("RIGHT");
        }
        else if(MAPA[x+1][y] == '-')
        {
            estado = Down();
            registro("DOWN");
        }
        else
        {
            if(ACT[ahora-1] == 'U')
            {
                etapACT[EtapaActual] = 'D';
                estado = Down();
            }
            else if(ACT[ahora-1] == 'D')
            {
                etapACT[EtapaActual] = 'U';
                estado = Up();
            }
            else if(ACT[ahora-1] == 'L')
            {
                etapACT[EtapaActual] = 'R';
                estado = Right();
            }
            else if(ACT[ahora-1] == 'R')
            {
                etapACT[EtapaActual] = 'L';
                estado = Left();
            }
            else if(ACT[ahora-1] == 'I')
            {
                etapa = 2;
                if (dirty_) return actSUCK;
                else return actIDLE;
            }
            registro("REGRESAR");
        }

    }

    else if(etapa == 2)
    {
        if (dirty_) return actSUCK;
        contador++;
        if(contador == EtapaActual) contador = 0;
        if(etapACT[contador] == 'U') return actUP;
        else if(etapACT[contador] == 'D') return actDOWN;
        else if(etapACT[contador] == 'L') return actLEFT;
        else if(etapACT[contador] == 'R') return actRIGHT;
        else if(etapACT[contador] == 'I')
        {
            if (dirty_) return actSUCK;
            return actIDLE;
        }
    }

    if(estado == "UP") return actUP;
    else if(estado == "DOWN") return actDOWN;
    else if(estado == "RIGHT") return actRIGHT;
    else if(estado == "LEFT") return actLEFT;
    else if(estado == "IDLE")
    {
        if (dirty_) return actSUCK;
        return actIDLE;
    }
}
// -----------------------------------------------------------
string Agent::Up()
{
    if(MAPA[x][y] == '-')
        MAPA[x][y] = 'R';
    x = x-1;
    return "UP";
}
// -----------------------------------------------------------
string Agent::Down()
{
    if(MAPA[x][y] == '-')
        MAPA[x][y] = 'R';
    x = x+1;
    return "DOWN";
}
// -----------------------------------------------------------
string Agent::Left()
{
    if(MAPA[x][y] == '-')
        MAPA[x][y] = 'R';
    y = y-1;
    return "LEFT";
}
// -----------------------------------------------------------
string Agent::Right()
{
    if(MAPA[x][y] == '-')
        MAPA[x][y] = 'R';
    y = y+1;
    return "RIGHT";
}
// -----------------------------------------------------------
void Agent::registro(string t)
{
    if(t == "VOLVER")
    {
        ahora -= 1;
        pos -= 2;
        EtapaActual--;
        return;
    }
    if(t == "REGRESAR")
    {
        ahora -= 1;
        pos -= 2;
        EtapaActual++;
        return;
    }

    if(t == "UP")
    {
        ACT[ahora] = 'U';
        etapACT[EtapaActual] = 'U';
    }
    else if(t == "DOWN")
    {
        ACT[ahora] = 'D';
        etapACT[EtapaActual] = 'D';
    }
    else if(t == "LEFT")
    {
        ACT[ahora] = 'L';
        etapACT[EtapaActual] = 'L';
    }
    else if(t == "RIGHT")
    {
        ACT[ahora] = 'R';
        etapACT[EtapaActual] = 'R';
    }

    posicion[pos] = x;
    posicion[pos+1] = y;

    ahora += 1;
    pos += 2;
    EtapaActual += 1;

}
// -----------------------------------------------------------
void Agent::Perceive(const Environment &env)
{
    bump_ = env.isJustBump();
    dirty_ = env.isCurrentPosDirty();
}
// -----------------------------------------------------------
string ActionStr(Agent::ActionType action)
{
    switch (action)
    {
    case Agent::actUP: return "UP";
    case Agent::actDOWN: return "DOWN";
    case Agent::actLEFT: return "LEFT";
    case Agent::actRIGHT: return "RIGHT";
    case Agent::actSUCK: return "SUCK";
    case Agent::actIDLE: return "IDLE";
    default: return "???";
    }
}
// -----------------------------------------------------------
