#include "c2d2\chien2d2.h"
#include "c2d2\chien2d2primitivas.h"
#include "c2d2/chienaudio2.h"


#include "Recursos.h"

/* Função para carregar os recursos áudio-visuais do jogo. */
void Recursos::CarregaRecursos()
{
	// Caso esteja tocando música ou efeito sonoro, evita maiores problemas
	CA2_FadeMusica(0);

	strcpy(diretorio, "./files");

	// Carrega os recursos, imprimindo o nome dos arquivos junto com o nome do diretório
	// Fonte do sistema
	sprintf(nome, "%s/fonte.png", diretorio);
	fonte = C2D2_CarregaFonte(nome, 32);
	// A tela de fundo do titulo
	sprintf(nome, "%s/menus/titulo.png", diretorio);
	titulo = C2D2_CarregaSpriteSet(nome, 0, 0);
	sprintf(nome, "%s/sprites/cursormouse.png", diretorio);
	cursor = C2D2_CarregaSpriteSet(nome, 0, 0);
	// Carrega os botões do menu principal
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
	sprintf(nome, "%s/debug2.png", diretorio);
	spNave2 = C2D2_CarregaSpriteSet(nome, 75, 75);
	sprintf(nome, "%s/sprites/tiro.png", diretorio);
	spTiro = C2D2_CarregaSpriteSet(nome, 8, 8);
	sprintf(nome, "%s/sprites/geometroide_pequeno1.png", diretorio);
	spGeomPeq1 = C2D2_CarregaSpriteSet(nome, 17, 17);

	// O efeito do mouse passando em cima de uma opção do menu
	sprintf(nome, "%s/audio/menu_sobre.ogg", diretorio);
	menuSobre = CA2_CarregaEfeito(nome);
	// O efeito de quando uma opção do menu é selecionada
	sprintf(nome, "%s/audio/menu_escolhe.ogg", diretorio);
	menuEscolhe = CA2_CarregaEfeito(nome);
	// Efeitos dos personagens
	sprintf(nome, "%s/audio/tiro.ogg", diretorio);
	jogoTiro = CA2_CarregaEfeito(nome);

	// Carrega música
	sprintf(nome, "./files/audio/musica.ogg", diretorio);
	mfundo = CA2_CarregaMusica(nome);

	// Carrega Fundo
	sprintf(nome, "%s/fundo.png", diretorio);
	spFundo = C2D2_CarregaSpriteSet(nome, 1024, 768);
}

/* Função para descarregar os recursos áudio-visuais do jogo. */
void Recursos::RemoveRecursos()
{
	// Remove a fonte da memória
	C2D2_RemoveFonte(fonte);
	// REmove a tela de título
	C2D2_RemoveSpriteSet(titulo);
	// Remove o cursor do mouse
	C2D2_RemoveSpriteSet(cursor);
	// Remove os botões da tela de título
	C2D2_RemoveSpriteSet(botaoJogar);
	C2D2_RemoveSpriteSet(botaoRecordes);
	C2D2_RemoveSpriteSet(botaoOpcoes);
	C2D2_RemoveSpriteSet(botaoCreditos);
	C2D2_RemoveSpriteSet(botaoSair);
	C2D2_RemoveSpriteSet(spGeomPeq1);

	// Remove os personagens
	C2D2_RemoveSpriteSet(spNave);
	C2D2_RemoveSpriteSet(spTiro);
	// Remove o efeito do mouse passando na opção
	CA2_RemoveEfeito(menuSobre);
	menuSobre = 0;
	// Remove o efeito do mouse escolhendo a opção
	CA2_RemoveEfeito(menuEscolhe);
	menuEscolhe = 0;
	CA2_RemoveEfeito(jogoTiro);

	CA2_RemoveMusica(mfundo);

}