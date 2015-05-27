// SuperSoulWings.h : Define includes, constantes e fun��es da aplica��o.
//

// Includes
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include <time.h>
#include "c2d2\chien2d2.h"
#include "c2d2\chien2d2primitivas.h"
#include "c2d2/chienaudio2.h"

// Telas do Menu do jogo
enum { TELA_PRINCIPAL, TELA_JOGO, TELA_OPCOES, TELA_CREDITOS, TELA_RECORDES };

// Estados de um bot�o
enum { BOTAO_INATIVO, BOTAO_RECEMSELECIONADO, BOTAO_SELECIONADO };

// Indica o estado do jogo
int estadoJogo = TELA_PRINCIPAL;

// Indica se deve encerrar a aplica��o
bool quit = false;

// tipo de dado para o personagem
typedef struct
{
	// Tipo do personagem
	int tipo;
	// Posi��o
	int x, y;
	// Velocidade nos eixos x e y
	int dx, dy;
	// Vari�vel exclusiva do tiro do jogador, indica aonde come�ou
	int xInicial, yInicial;
}Personagem;

// Prot�tipos das Fun��es
void TelaPrincipal();
void TelaJogo();
void TelaAzul();
void DesenhaPersonagem(Personagem *pers);

// Os tipos de personagens
enum { INVALIDO, NAVE, ANJO, DEMON, TIRO };



// Outras defini��es
// M�sica do demo
unsigned int mfundo = 0;

// Vari�veis para os recursos visuais do jogo
unsigned int fonte = 0;
unsigned int titulo = 0;
unsigned int cursor = 0;

// Variaveis dos botoes do menu principal
unsigned int botaoJogar = 0, botaoRecordes = 0, botaoOpcoes = 0, botaoCreditos = 0, botaoSair = 0;

// Carrega os arquivos do jogo
char nome[512], diretorio[64];
// Escolhe o diret�rio base dos recursos

// Vari�veis para os personagens
unsigned int spNave = 0, spTiro = 0, spGeomPeq1 = 0;

// Vari�veis do cen�rio
unsigned int spFundo = 0;

// Vari�veis para os recursos de �udio do jogo
unsigned int menuSobre = 0;
unsigned int menuEscolhe = 0;
unsigned int jogoTiro = 0;



/* Fun��o para carregar os recursos �udio-visuais do jogo. */
void CarregaRecursos()
{
	// Caso esteja tocando m�sica ou efeito sonoro, evita maiores problemas
	CA2_FadeMusica(0);
			
	strcpy(diretorio, "./files");

	// Carrega os recursos, imprimindo o nome dos arquivos junto com o nome do diret�rio
	// Fonte do sistema
	sprintf(nome, "%s/fonte.png", diretorio);
	fonte = C2D2_CarregaFonte(nome, 32);
	// A tela de fundo do titulo
	sprintf(nome, "%s/menus/titulo.png", diretorio);
	titulo = C2D2_CarregaSpriteSet(nome, 0, 0);
	sprintf(nome, "%s/sprites/cursormouse.png", diretorio);
	cursor = C2D2_CarregaSpriteSet(nome, 0, 0);
	// Carrega os bot�es do menu principal
	sprintf(nome, "%s/menus/principal_jogar.png", diretorio);
	botaoJogar = C2D2_CarregaSpriteSet(nome, 200, 40);
	sprintf(nome, "%s/menus/principal_recordes.png", diretorio);
	botaoRecordes = C2D2_CarregaSpriteSet(nome, 200, 40);
	sprintf(nome, "%s/menus/principal_opcoes.png", diretorio);
	botaoOpcoes = C2D2_CarregaSpriteSet(nome, 200, 40);
	sprintf(nome, "%s/menus/principal_creditos.png", diretorio);
	botaoCreditos = C2D2_CarregaSpriteSet(nome, 200, 40);
	sprintf(nome, "%s/menus/principal_sair.png", diretorio);
	botaoSair = C2D2_CarregaSpriteSet(nome, 200, 40);
	// Carrega os personagens
	sprintf(nome, "%s/debug1.png", diretorio);
	spNave = C2D2_CarregaSpriteSet(nome, 75, 75);
	sprintf(nome, "%s/sprites/tiro.png", diretorio);
	spTiro = C2D2_CarregaSpriteSet(nome, 8, 8);
	sprintf(nome, "%s/sprites/geometroide_pequeno1.png", diretorio);
	spGeomPeq1 = C2D2_CarregaSpriteSet(nome, 17, 17);

	// O efeito do mouse passando em cima de uma op��o do menu
	sprintf(nome, "%s/audio/menu_sobre.ogg", diretorio);
	menuSobre = CA2_CarregaEfeito(nome);
	// O efeito de quando uma op��o do menu � selecionada
	sprintf(nome, "%s/audio/menu_escolhe.ogg", diretorio);
	menuEscolhe = CA2_CarregaEfeito(nome);
	// Efeitos dos personagens
	sprintf(nome, "%s/audio/tiro.ogg", diretorio);
	jogoTiro = CA2_CarregaEfeito(nome);

	// Carrega m�sica
	sprintf(nome, "%s/audio/musica.ogg", diretorio);
	mfundo = CA2_CarregaMusica(nome);

	// Carrega Fundo
	sprintf(nome, "%s/fundo.png", diretorio);
	spFundo = C2D2_CarregaSpriteSet(nome, 1024, 768);
}

/* Fun��o para descarregar os recursos �udio-visuais do jogo. */
void RemoveRecursos()
{
	// Remove a fonte da mem�ria
	C2D2_RemoveFonte(fonte);
	// REmove a tela de t�tulo
	C2D2_RemoveSpriteSet(titulo);
	// Remove o cursor do mouse
	C2D2_RemoveSpriteSet(cursor);
	// Remove os bot�es da tela de t�tulo
	C2D2_RemoveSpriteSet(botaoJogar);
	C2D2_RemoveSpriteSet(botaoRecordes);
	C2D2_RemoveSpriteSet(botaoOpcoes);
	C2D2_RemoveSpriteSet(botaoCreditos);
	C2D2_RemoveSpriteSet(botaoSair);
	C2D2_RemoveSpriteSet(spGeomPeq1);

	// Remove os personagens
	C2D2_RemoveSpriteSet(spNave);
	C2D2_RemoveSpriteSet(spTiro);
	// Remove o efeito do mouse passando na op��o
	CA2_RemoveEfeito(menuSobre);
	menuSobre = 0;
	// Remove o efeito do mouse escolhendo a op��o
	CA2_RemoveEfeito(menuEscolhe);
	menuEscolhe = 0;
	CA2_RemoveEfeito(jogoTiro);

	CA2_RemoveMusica(mfundo);

}