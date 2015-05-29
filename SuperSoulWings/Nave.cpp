#include "c2d2\chien2d2.h"
#include "c2d2\chien2d2primitivas.h"
#include "c2d2/chienaudio2.h"

#include "Nave.h"


// Máximo vida nave
const int MAXVida = 100;
const int Velocidade = 3;

Nave::Nave(long x, long y, long tipo, long Sp)
{
	// Coordenadas Iniciais
	xInicial = x;
	this->x = x;
	yInicial = y;
	this->y = y;
	this->Sp = Sp;

	// Tipo do personagem, vida e sprite atual
	this->tipo = tipo;
	vida = MAXVida;
	SpAtual = 0;
	animind = 0;
	animquadro = 30;
	// Selecionar Sprite
	if (this->tipo == 0){
		
		limesq = 0;
		limdir = 455;
		limcim = 200;
		limbai = 600;
		animacao[0][0] = 0;
		animacao[0][1] = 1;
		animacao[0][2] = 2;
		animacao[1][0] = 0;
		animacao[1][1] = 3;
		animacao[1][2] = 4;
	}
	else{
		
		limesq = 513;
		limdir = 987;
		limcim = 200;
		limbai = 600;
		animacao[0][0] = 0;
		animacao[0][1] = 1;
		animacao[0][2] = 2;
		animacao[1][0] = 0;
		animacao[1][1] = 3;
		animacao[1][2] = 4;
	}
}

void Nave::desenhar(){

	C2D2_DesenhaSprite(Sp, animacao[animind][SpAtual], x, y);

}

void Nave::movesq(){
	
		if ((this->x - Velocidade) < limesq)
			this->x = limesq;
		else
			this->x = this->x - Velocidade;

		if (--animquadro == 0) // Animação
		{	
			animind = 0;
			SpAtual = (SpAtual + 1) % 3;
			animquadro = 30;
		}

}

void Nave::movdir(){

		if ((this->x + Velocidade) > limdir)
			this->x = limdir;
		else
			this->x = this->x + Velocidade;

		if (--animquadro == 0) // Animação
		{	
			animind = 1;
			SpAtual = (SpAtual + 1) % 3;
			animquadro = 30;
		}
}

void Nave::movcim(){

	if ((this->y - Velocidade) < limcim)
		this->y = limcim;
	else
		this->y = this->y - Velocidade;
}

void Nave::movbai(){

	if ((this->y + Velocidade) > limbai)
		this->y = limbai;
	else
		this->y = this->y + Velocidade;
}
