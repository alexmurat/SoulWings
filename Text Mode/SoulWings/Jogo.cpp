/**
Classe  : Jogo
Objetivo: Controla o jogo - Invocação dos anjos/demônios, controle da nave e pontuação
**/

#include <stdlib.h>
#include <stdio.h>
#include <conio.h>
#include "console.h"

//#include "Controlador.h"
#include "Jogo.h"

#include <windows.h>


/**
Método  : Jogo (Construtor)
Objetivo: Inicializa variáveis e executa abertura do jogo
**/
Jogo::Jogo()
{
	pontuacao = 0; // Iniciando Pontuação equilibrada

	for (int i=0; i<MAX; i++) // Iniciando lista de Anjos/Demonios
		lista[i] = NULL;

	abrirjogo(); // Tela inicial do Jogo
}

/**
Método  : executar
Objetivo: Loop principal do jogo
**/
void Jogo::executar()
{
	bool fim = false;
	criarNaves();

	do
	{
		//Move todos os anjos e demonios vivos
		for (int i=0; i<MAX; i++)
			if (lista[i] != NULL)
			{
			   if (!lista[i]->mover())
			   {
				   
				   if (MinhaNave->gety() == lista[i]->gety()) // Verifica a colisão com a nave 1
					   pontuacao++;

				   if (MinhaNave2->gety() == lista[i]->gety()) // Verifica a colisão com a nave 2
					   pontuacao--;
				   
				   //Caso tenha alcançado o final da tela, elimina o anjo ou demonio
				   mostrar(0, lista[i]->gety(), BACKGROUND_BLACK, " "); // Limpar para não deixar resquicios na tela
				   delete lista[i];
				   lista[i] = NULL;
				   

				   //Verifica se o jogador venceu ou perdeu
				   if (pontuacao == 5)
				   {
				      finalizarjogo(true);
				      return;
				   }
				   else if(pontuacao == -5)
				   {
					   finalizarjogo(false);
					   return;
				   }


			   }
			}

		//Cria novos anjos e demonios
		criar();

		//Desenha Plano de Fundo e Placar
		desenhar();
		//Desenha Naves
		MinhaNave->desenhar();
		MinhaNave2->desenhar();

		Sleep(100);

	} while (verificar());
}


/**
Método  : verificar
Objetivo: Faz a leitura de entradas do teclado e Controla as Naves
**/
bool Jogo::verificar()
{

	if (kbhit())
	{
		char c = getch();
		
		if (isalpha(c)){
			switch (c){
			case 'w':
				MinhaNave->mover(0);
				MinhaNave2->mover2(1); // Nave debaixo se move invertido
				break;
			case 's':
				MinhaNave->mover(1);
				MinhaNave2->mover2(0); // Nave debaixo se move invertido
				break;
			}
		}
		else
		//Tecla ESC sai do jogo
		if (c == 27)
			return false;
	}
	return true;
}


/**
Método  : criar
Objetivo: Cria novos Anjos/Demonios, respeitando o máximo de vivos permitidos
**/
void Jogo::criar()
{
	for (int i=0; i < MAX; i++)
		if (lista[i] == NULL)
			lista[i] = new Controlador(LIMITE);
}

void Jogo::criarNaves()
{
	// Iniciam fixas no meio de suas telas
	MinhaNave = new Nave(7); 
	MinhaNave2 = new Nave(17);
}

/**
Método  : abrirjogo
Objetivo: Tela Inicial.
**/
void Jogo::abrirjogo()
{
	clrscr();

	mostrar(15, 1, FOREGROUND_WHITE, " __             _ __    __ _                 ");
	mostrar(15, 2, FOREGROUND_WHITE, "/ _\\ ___  _   _| / / /\\ \\ (_)_ __   __ _ ___ ");
	mostrar(15, 3, FOREGROUND_WHITE, "\\ \\ / _ \\| | | | \\ \\/  \\/ / | '_ \\ / _` / __|");
	mostrar(15, 4, FOREGROUND_RED, "_\\ \\ (_) | |_| | |\\  /\\  /| | | | | (_| \__ \\");
	mostrar(15, 5, FOREGROUND_RED, "\\__/\\___/ \\__,_|_| \\/  \\/ |_|_| |_|\\__, |___/");
	mostrar(15, 6, FOREGROUND_RED, "                                   |___/     ");

	mostrar(2, 8, FOREGROUND_WHITE, "   Uma asa esta no mundo real, a outra se reflete no mundo das almas...   ");
	mostrar(2, 10, FOREGROUND_WHITE, "   O ceu e o inferno estao em guerra...   ");
	mostrar(2, 11, FOREGROUND_WHITE, "   Resgate os anjos e escape dos demonios...   ");
	
	mostrar(2, 17, FOREGROUND_RED, "   Comandos:   ");
	mostrar(2, 19, FOREGROUND_WHITE, "   W - Subir   ");
	mostrar(2, 20, FOREGROUND_WHITE, "   S - Descer   ");
	mostrar(2, 21, FOREGROUND_WHITE, "   Esc - Sair do Jogo   ");
	mostrar(2, 23, FOREGROUND_RED, "   Tecle qualquer tecla para iniciar, e se prepare...   ");
	
	char c = getch();
	clrscr();
}

/**
Método  : finalizarjogo
Objetivo: Apresenta mensagens de final e termina o jogo. 
**/

void Jogo::finalizarjogo(bool vitoria)
{
	if (vitoria){
		mostrar(0, 12, BACKGROUND_BLACK | FOREGROUND_WHITE, "\t\t\t\t\t\t\t\t\t\t");
		mostrar(30, 12, BACKGROUND_BLACK | FOREGROUND_WHITE, "   Salvou o mundo!!!   ");
	}
	else{
		mostrar(0, 12, BACKGROUND_BLACK | FOREGROUND_RED, "\t\t\t\t\t\t\t\t\t\t");
		mostrar(30, 12, BACKGROUND_BLACK | FOREGROUND_RED, "Os demonios dominaram..");
	}
	char c=getch();
	Sleep(500);
	clrscr();
}

/**
Método  : desenhar
Objetivo: Desenha o cenário do jogo e o placar
**/
void Jogo::desenhar()
{
	//mostrar(0, 0, BACKGROUND_BLUE, "\t\t\t\t\t\t\t\t\t\t");
	mostrar(0, 1, BACKGROUND_BLUE, "\t\t\t\t\t\t\t\t\t\t");
	mostrar(0, 2, BACKGROUND_BLUE, "\t\t\t\t\t\t\t\t\t\t");
	//mostrar(0, 12, BACKGROUND_GREEN, "\t\t\t\t\t\t\t\t\t\t"); // Linha do meio
	mostrar(0, 22, BACKGROUND_BLUE, "\t\t\t\t\t\t\t\t\t\t");
	mostrar(0, 23, BACKGROUND_BLUE, "\t\t\t\t\t\t\t\t\t\t");
	//mostrar(0, 24, BACKGROUND_BLUE, "\t\t\t\t\t\t\t\t\t\t");

	//Placar
	//mostrar(0, 0, BACKGROUND_GREEN || FOREGROUND_RED, pontuacao); // debug

	// Exibir o Equilibrio do Placar de Pontuação
	switch (pontuacao){
		case -5: {
			//mostrar(0, 12, BACKGROUND_WHITE, "\t\t\t\t\t");
			mostrar(0, 12, BACKGROUND_RED, "\t\t\t\t\t\t\t\t\t\t");
			break;
		}
		case -4: {
					 mostrar(0, 12, BACKGROUND_WHITE, "\t");
					 mostrar(8, 12, BACKGROUND_RED, "\t\t\t\t\t\t\t\t\t");
					 break;
		}
		case -3: {
					 mostrar(0, 12, BACKGROUND_WHITE, "\t\t");
					 mostrar(16, 12, BACKGROUND_RED, "\t\t\t\t\t\t\t\t");
					 break;
		}
		case -2: {
					 mostrar(0, 12, BACKGROUND_WHITE, "\t\t\t");
					 mostrar(24, 12, BACKGROUND_RED, "\t\t\t\t\t\t\t");
					 break;
		}
		case -1: {
					 mostrar(0, 12, BACKGROUND_WHITE, "\t\t\t\t");
					 mostrar(32, 12, BACKGROUND_RED, "\t\t\t\t\t\t");
					 break; 
		}
		case 0: {
					mostrar(0, 12, BACKGROUND_WHITE, "\t\t\t\t\t");
					mostrar(40, 12, BACKGROUND_RED, "\t\t\t\t\t");
					break;
		}
		case 1: {
					mostrar(0, 12, BACKGROUND_WHITE, "\t\t\t\t\t\t");
					mostrar(48, 12, BACKGROUND_RED, "\t\t\t\t");
					break;
		}
		case 2: {
					mostrar(0, 12, BACKGROUND_WHITE, "\t\t\t\t\t\t\t");
					mostrar(56, 12, BACKGROUND_RED, "\t\t\t");
					break;
		}
		case 3: {
					mostrar(0, 12, BACKGROUND_WHITE, "\t\t\t\t\t\t\t\t");
					mostrar(64, 12, BACKGROUND_RED, "\t\t");
					break;
		}
		case 4: {
					mostrar(0, 12, BACKGROUND_WHITE, "\t\t\t\t\t\t\t\t\t");
					mostrar(72, 12, BACKGROUND_RED, "\t");
					break;
		}
		case 5: {
					mostrar(0, 12, BACKGROUND_WHITE, "\t\t\t\t\t\t\t\t\t\t");
					//mostrar(60, 12, BACKGROUND_RED, "\t\t\t\t");
					break;
		}
	}

	//mostrar(0, 24, BACKGROUND_GREEN, "\t\t\t\t\t\t\t\t\t\t");
}
