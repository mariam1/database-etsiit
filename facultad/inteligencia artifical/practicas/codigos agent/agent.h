
#ifndef AGENT__
#define AGENT__

#include <string>
using std::string;

// -----------------------------------------------------------
//				class Agent
// -----------------------------------------------------------
class Environment;
class Agent
{
public:
	Agent():bump_(false), dirty_(false), x(10), y(10), ahora(1), pos(2), estado("NULL"), contador(0), etapa(1), EtapaActual(1)
	{
		for(int i = 0; i<20; i++)
			for(int j = 0; j<20; j++)
				MAPA[i][j] = '-';
		for(int i = 0; i<2000; i++)
			ACT[i] = 'N';
		ACT[0] = 'I';
		for(int i = 0; i<10000; i++) etapACT[i] = 'I';
		for(int i = 0; i<4000; i++) posicion[i] = 0;
	}

	string Up(); //arriba = U
	string Down(); // abajo = D
	string Left(); //Izquierda = I
	string Right(); // Derecha = D

	void registro(string t);  //Memorizar accion anterior (registro)

	enum ActionType { actUP, actDOWN, actLEFT, actRIGHT, actIDLE, actSUCK };
	void Perceive(const Environment &env);
	ActionType Think();

private:
	bool bump_,
		 dirty_;
	int x, y, ahora, pos, EtapaActual;
	string estado;
	char MAPA[20][20];
	char ACT[2000];
	char etapACT[10000];
	int posicion[4000];
    int contador;
    int etapa;
};

string ActionStr(Agent::ActionType);

#endif
