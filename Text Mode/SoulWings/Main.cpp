#include <stdio.h>
#include <conio.h>
#include <time.h>
#include <windows.h>
#include "Console.h"
#include "Jogo.h"

// Author: Alex Murat

void main(){
	srand(time(NULL));

	// Iniciando um jogo
	Jogo MeuJogo;

	// Executar
	MeuJogo.executar();
}