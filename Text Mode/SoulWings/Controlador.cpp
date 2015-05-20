/**
Classe  : Controlador
**/

#include <stdlib.h>
#include "console.h"
#include "Controlador.h"

/**
Método  : Controlador (Construtor)
Objetivo: Inicia os valores dos anjos e demônios
**/
Controlador::Controlador(long limite)
{
	// Posição X inicial é fixa
   x = INICIO;  

   // Adquirindo a posição Y
   y = (rand() % 18) +3;
   if (y <= 12){ // Forçando a ter mais demônios do que anjos
	   y = (rand() % 18) + 3;
	   if (y == 12) // No lugar da linha do meio (onde fica o indicador de placar) invoca na ultima linha
		   y = 21;
   }

   if (y < 12){ // Anjos são um pouco mais lentos e brancos
	   cor = FOREGROUND_WHITE;
	   passo = rand() % PASSO + 2;
   }
   else{ // Demônios são um pouco mais rápidos e vermelhos
	   cor = FOREGROUND_RED;
	   passo = rand() % PASSO + 3;
   }

   // O limite da tela onde os anjos e demonios devem colidir com as naves ou desaparecer (Sempre 0)
   this->limite = limite;

   desenhar();
}


/**
Método  : ~Controlador
Objetivo: Apaga o objeto
**/
Controlador::~Controlador()
{
   apagar();
}


/**
Método  : desenhar
Objetivo: Desenha o anjo/demonio na tela
**/
void Controlador::desenhar()
{
	mostrar(x, y, cor, "*");
}


/**
Método  : mover
Objetivo: Move (ou não) o anjo/demonio na tela
**/
bool Controlador::mover()
{
    if (x-passo < limite)
      return false;

	apagar();

    x -= passo;

	desenhar();

    return true;
}


/**
Método  : apagar
Objetivo: Apaga o rastro do anjo/demonio
**/
void Controlador::apagar()
{
   for (int i=0; i<=passo; i++)
      if (x >= 1)
        mostrar(x+i, y, cor, " ");
}