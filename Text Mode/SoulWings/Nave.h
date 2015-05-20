/**
Classe  : Nave (No jogo me refiro as naves como asas)
Objetivo: Controla as naves do jogo, movimento e impress�o
**/

class Nave
{
private:
	long y;    //posi��o da nave

public:
	Nave();
	Nave(long y);

	void desenhar();
	bool mover(int direcao);
	bool mover2(int direcao);
	void apagar();

	long gety() { return y; }

};