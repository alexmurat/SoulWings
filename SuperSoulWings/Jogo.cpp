// Inicial

//Includes
#include <stdio.h>
#include <tchar.h>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include <time.h>

#include "c2d2\chien2d2.h"
#include "c2d2\chien2d2primitivas.h"
#include "c2d2/chienaudio2.h"

#include "Jogo.h"
#include "Nave.h"

int main(int narg, char **valarg)
{
	// Iniciando um jogo
	Jogo MeuJogo;

	// Executar
	MeuJogo.MenuInicial();
	
	return 0;
}

Jogo::Jogo()
{

	estadoJogo = TELA_PRINCIPAL;
	quit = false;

}

void Jogo::MenuInicial(){

	// Inicia a Chien2D 2 e testa se deu tudo certo
	if (C2D2_Inicia(1024, 768, C2D2_JANELA, C2D2_DESENHO_PADRAO, "SoulWings"))
		printf("Iniciou a Chien2D 2 com sucesso\n");
	else
	{
		printf("Falhou ao iniciar a Chien2D 2. Encerrando o programa.\n");
	}

	rc = Recursos();
	
	CA2_Inicia(); // Inicia o módulo de áudio

	rc.CarregaRecursos(); // Função de remover recursos do jogo

	

	// Captura o teclado
	C2D2_Botao *teclado = C2D2_PegaTeclas();

	do
	{
		switch (estadoJogo)
		{
		case TELA_PRINCIPAL:
			TelaPrincipal();
			break;
		case TELA_JOGO:
			TelaJogo();
			break;
		default:
			TelaAzul();
			break;
		}
	} while (!quit);

	rc.RemoveRecursos(); // Função de remover recursos do jogo

};

void Jogo::TelaJogo(){

	C2D2_Botao *teclado = C2D2_PegaTeclas();

	Nave Angel = Nave(209, 600, 0, rc.spNave);
	Nave Demon = Nave(741, 600, 1, rc.spNave2);

	while (estadoJogo == TELA_JOGO && !teclado[C2D2_ESC].pressionado && !teclado[C2D2_ENCERRA].ativo)
	{
		C2D2_LimpaTela();
		C2D2_DesenhaSprite(rc.spFundo, 0, 0, 0);

		Angel.desenhar();
		Demon.desenhar();

		if (teclado[C2D2_ESQUERDA].liberado || teclado[C2D2_DIREITA].liberado || teclado[C2D2_CIMA].liberado || teclado[C2D2_BAIXO].liberado){
			Angel.SpAtual = 0;
			Demon.SpAtual = 0;
		}

		if (teclado[C2D2_ESQUERDA].ativo){
			Angel.movesq();
			Demon.movdir();

		}
		if (teclado[C2D2_DIREITA].ativo){
			Angel.movdir();
			Demon.movesq();
		}
		if (teclado[C2D2_CIMA].ativo){
			Angel.movcim();
			Demon.movcim();
		}
		if (teclado[C2D2_BAIXO].ativo){
			Angel.movbai();
			Demon.movbai();
		}

		C2D2_Sincroniza(C2D2_FPS_PADRAO);
	}
	// Indica que deve voltar ao menu principal
	estadoJogo = TELA_PRINCIPAL;

}

void Jogo::TelaPrincipal()
{
	// Captura o teclado
	C2D2_Botao *teclado = C2D2_PegaTeclas();

	// Variáveis para o estado dos botões
	int jogar = BOTAO_SELECIONADO, opcoes = BOTAO_INATIVO, recordes = BOTAO_INATIVO,
		creditos = BOTAO_INATIVO, sair = BOTAO_INATIVO;

	// Controle do Menu
	int menu = 0;

	CA2_TocaMusica(rc.mfundo, 100);

	// Repete indefinidamente
	while (estadoJogo == TELA_PRINCIPAL && !quit)
	{
		// Aqui fazemos a lógica do menu
		//
		// Se pressionou ESC, encerra
		if (teclado[C2D2_ESC].pressionado || teclado[C2D2_ENCERRA].ativo)
		{
			quit = true;
			break;
		}

		if (teclado[C2D2_CIMA].pressionado && menu > 0){
			menu--;
			CA2_TocaEfeito(rc.menuSobre, 0);
		}
		if (teclado[C2D2_BAIXO].pressionado && menu < 4){
			menu++;
			CA2_TocaEfeito(rc.menuSobre, 0);
		}

		switch (menu){
		case 0:
			jogar = BOTAO_SELECIONADO;
			opcoes = BOTAO_INATIVO;
			recordes = BOTAO_INATIVO;
			creditos = BOTAO_INATIVO;
			sair = BOTAO_INATIVO;
			if (teclado[C2D2_ENTER].pressionado)
			{
				CA2_FadeMusica(1500);
				estadoJogo = TELA_JOGO;
			}
			break;

		case 1:
			jogar = BOTAO_INATIVO;
			opcoes = BOTAO_SELECIONADO;
			recordes = BOTAO_INATIVO;
			creditos = BOTAO_INATIVO;
			sair = BOTAO_INATIVO;
			if (teclado[C2D2_ENTER].pressionado)
			{
				CA2_TocaEfeito(rc.menuEscolhe, 0);
				estadoJogo = TELA_OPCOES;
			}
			break;

		case 2:
			jogar = BOTAO_INATIVO;
			opcoes = BOTAO_INATIVO;
			recordes = BOTAO_SELECIONADO;
			creditos = BOTAO_INATIVO;
			sair = BOTAO_INATIVO;
			if (teclado[C2D2_ENTER].pressionado)
			{
				CA2_TocaEfeito(rc.menuEscolhe, 0);
				estadoJogo = TELA_RECORDES;
			}
			break;

		case 3:
			jogar = BOTAO_INATIVO;
			opcoes = BOTAO_INATIVO;
			recordes = BOTAO_INATIVO;
			creditos = BOTAO_SELECIONADO;
			sair = BOTAO_INATIVO;
			if (teclado[C2D2_ENTER].pressionado)
			{
				CA2_TocaEfeito(rc.menuEscolhe, 0);
				estadoJogo = TELA_CREDITOS;
			}
			break;
		case 4:
			jogar = BOTAO_INATIVO;
			opcoes = BOTAO_INATIVO;
			recordes = BOTAO_INATIVO;
			creditos = BOTAO_INATIVO;
			sair = BOTAO_SELECIONADO;
			if (teclado[C2D2_ENTER].pressionado)
			{
				CA2_TocaEfeito(rc.menuEscolhe, 0);
				quit = true;
			}
			break;
		}


		// Aqui fazemos o desenho do menu
		C2D2_LimpaTela();
		// DEsenha o titulo
		C2D2_DesenhaSprite(rc.titulo, 0, 0, 0);
		// DEsenha os botões
		if (jogar == BOTAO_INATIVO)
			C2D2_DesenhaSprite(rc.botaoJogar, 0, 412, 300);
		else
			C2D2_DesenhaSprite(rc.botaoJogar, 1, 412, 300);
		if (opcoes == BOTAO_INATIVO)
			C2D2_DesenhaSprite(rc.botaoOpcoes, 0, 412, 350);
		else
			C2D2_DesenhaSprite(rc.botaoOpcoes, 1, 412, 350);
		if (recordes == BOTAO_INATIVO)
			C2D2_DesenhaSprite(rc.botaoRecordes, 0, 412, 400);
		else
			C2D2_DesenhaSprite(rc.botaoRecordes, 1, 412, 400);
		if (creditos == BOTAO_INATIVO)
			C2D2_DesenhaSprite(rc.botaoCreditos, 0, 412, 450);
		else
			C2D2_DesenhaSprite(rc.botaoCreditos, 1, 412, 450);
		if (sair == BOTAO_INATIVO)
			C2D2_DesenhaSprite(rc.botaoSair, 0, 412, 500);
		else
			C2D2_DesenhaSprite(rc.botaoSair, 1, 412, 500);

		// Créditos básicos
		C2D2_DesenhaTexto(rc.fonte, 512, 700, "© 2015 por Alex Murat", C2D2_TEXTO_CENTRALIZADO);


		C2D2_Sincroniza(C2D2_FPS_PADRAO);
	}
}

void Jogo::TelaAzul()
{
	C2D2_Botao *teclado = C2D2_PegaTeclas();
	while (!teclado[C2D2_ESC].pressionado && !teclado[C2D2_ENCERRA].ativo)
	{
		C2D2_TrocaCorLimpezaTela(0, 0, 255);
		C2D2_LimpaTela();
		C2D2_DesenhaTexto(rc.fonte, 512, 268, "Tela em desenvolvimento.", C2D2_TEXTO_CENTRALIZADO);
		C2D2_DesenhaTexto(rc.fonte, 512, 500, "Pressione ESC para encerrar a aplicação.", C2D2_TEXTO_CENTRALIZADO);
		C2D2_Sincroniza(C2D2_FPS_PADRAO);
	}
	// Indica que deve encerrar
	quit = true;
}
