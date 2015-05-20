/**
Classe  : Controlador
**/

#include <stdlib.h>
#include "console.h"
#include "Controlador.h"

/**
M�todo  : Controlador (Construtor)
Objetivo: Inicia os valores dos anjos e dem�nios
**/
Controlador::Controlador(long limite)
{
	// Posi��o X inicial � fixa
   x = INICIO;  

   // Adquirindo a posi��o Y
   y = (rand() % 18) +3;
   if (y <= 12){ // For�ando a ter mais dem�nios do que anjos
	   y = (rand() % 18) + 3;
	   if (y == 12) // No lugar da linha do meio (onde fica o indicador de placar) invoca na ultima linha
		   y = 21;
   }

   if (y < 12){ // Anjos s�o um pouco mais lentos e brancos
	   cor = FOREGROUND_WHITE;
	   passo = rand() % PASSO + 2;
   }
   else{ // Dem�nios s�o um pouco mais r�pidos e vermelhos
	   cor = FOREGROUND_RED;
	   passo = rand() % PASSO + 3;
   }

   // O limite da tela onde os anjos e demonios devem colidir com as naves ou desaparecer (Sempre 0)
   this->limite = limite;

   desenhar();
}


/**
M�todo  : ~Controlador
Objetivo: Apaga o objeto
**/
Controlador::~Controlador()
{
   apagar();
}


/**
M�todo  : desenhar
Objetivo: Desenha o anjo/demonio na tela
**/
void Controlador::desenhar()
{
	mostrar(x, y, cor, "*");
}


/**
M�todo  : mover
Objetivo: Move (ou n�o) o anjo/demonio na tela
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
M�todo  : apagar
Objetivo: Apaga o rastro do anjo/demonio
**/
void Controlador::apagar()
{
   for (int i=0; i<=passo; i++)
      if (x >= 1)
        mostrar(x+i, y, cor, " ");
}