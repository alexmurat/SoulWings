/**
Classe  : Nave (No jogo me refiro as naves como asas)
Objetivo: Controla as naves do jogo, movimento e impress�o
**/

#include <stdlib.h>
#include "console.h"
#include "Nave.h"

/**
M�todo  : Nave (Construtor)
Objetivo: Criar a nave e coloca-la na tela
**/
Nave::Nave(long y)
{
	this->y = y;
	desenhar();
}

/**
M�todo  : desenhar
Objetivo: Desenhar a nave na tela
**/
void Nave::desenhar()
{
	//mostrar(0, y, FOREGROUND_YELLOW, "*");
	mostrar(0, y, FOREGROUND_YELLOW, "\xAF");

}

/**
M�todo  : mover
Objetivo: Mover a nave
**/
bool Nave::mover(int direcao)
{
	apagar();

	// Movimento � limitado 
	if (direcao == 0 && y > 3) // Subir
		y--;
		//return false;
	if (direcao == 1 && y < 11) // Descer
		y++;

	desenhar();

	return true;
}

/**
M�todo  : mover2
Objetivo: Mover a nave 2, criada para facilitar o movimento de espelho das naves
**/
bool Nave::mover2(int direcao)
{
	apagar();

	// Movimento � limitado
	if (direcao == 0 && y > 13) // Subir
		y--;
	if (direcao == 1 && y < 21) // Descer
		y++;

	desenhar();

	return true;
}

/**
M�todo  : apagar
Objetivo: Apagar o rasto da nave
**/
void Nave::apagar()
{
		mostrar(0, y, BACKGROUND_BLACK, " ");
}
