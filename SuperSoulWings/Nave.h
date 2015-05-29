#include <stdio.h>
#include <tchar.h>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include <time.h>

// Os tipos de personagens
enum { INVALIDO, NAVE, ANJO, DEMON, TIRO };

class Nave
{
private:

	long xInicial, yInicial;	//posição inicial da nave
	long x, y;    //posição atual da nave
	long vida; //Vida da nave
	long tipo; //0 - Angel , 1 - Demon
	long Sp; //SpriteSheet do personagem
	
	long limesq; // Limite Esquerda
	long limdir; // Limite Direita
	long limcim; // Limite Cima
	long limbai; // Limite Baixo

	long animind;
	long animacao[3][3];
	long animquadro;

public:
	Nave(long x, long y, long tipo, long Sp); //Construtor

	
	long SpAtual; // SpriteAtual
	void desenhar();
	void movesq();
	void movdir();
	void movcim();
	void movbai();

	long getposicaox() { return x; };
	long getposicaoy() { return y; };

}; 