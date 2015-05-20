/**
Classe  : Nave (No jogo me refiro as naves como asas)
Objetivo: Controla as naves do jogo, movimento e impressão
**/

class Nave
{
private:
	long y;    //posição da nave

public:
	Nave();
	Nave(long y);

	void desenhar();
	bool mover(int direcao);
	bool mover2(int direcao);
	void apagar();

	long gety() { return y; }

};