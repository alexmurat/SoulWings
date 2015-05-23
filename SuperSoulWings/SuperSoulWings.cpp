// SuperSoulWings.cpp : Defines the entry point for the console application.
//

// Chamar cabe�alho
#include "SuperSoulWings.h"


int main(int narg, char **valarg)
{

	// Inicia a Chien2D 2 e testa se deu tudo certo
	if (C2D2_Inicia(1024, 768, C2D2_JANELA, C2D2_DESENHO_PADRAO, "SoulWings"))
		printf("Iniciou a Chien2D 2 com sucesso\n");
	else
	{
		printf("Falhou ao iniciar a Chien2D 2. Encerrando o programa.\n");
		return 0;
	}

	// Inicia o �udio
	CA2_Inicia();

	// Carrega os recursos do jogo
	CarregaRecursos();

	// A repeti��o principal do jogo
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

	/*C2D2P_Inicia();

	// Recupera o teclado
	C2D2_Botao *teclas = C2D2_PegaTeclas();

	// Troca a cor de fundo da tela
	C2D2_TrocaCorLimpezaTela(0, 0, 0);

	// Cria o personagem do jogo
	unsigned int Nave = C2D2_CarregaSpriteSet("./Imagens/naves.png", 62, 62);

	// Vari�veis para animar o personagem
	int xpers = 100;
	int ypers = 100;
	int qpers[8] = { 0, 1, 2, 3, 4, 5, 6, 7 };
	int qatual = 0;
	int tquadro = 10;

	do{
	
		qatual = 0;
	
		if (teclas[C2D2_ESQUERDA].ativo){
			xpers -= 2;
			qatual = 3;
		}
		else if (teclas[C2D2_DIREITA].ativo){
			xpers += 2;
			qatual = 3;
		}
	
		C2D2_LimpaTela();
	
		// Desenha o sprite
		C2D2_DesenhaSprite(Nave, qpers[qatual], xpers, ypers);
	
		// Faz a troca do front buffer com o back buffer e atualiza as entradas
		C2D2_Sincroniza(C2D2_FPS_PADRAO);
	
	} while (!teclas[C2D2_ENCERRA].pressionado && !teclas[C2D2_ESC].pressionado);

	// Remove as imagens
	C2D2_RemoveSpriteSet(Nave);

	// Encerra a Chien2D 2
	C2D2_Encerra();*/

	return 0;
}

// A fun��o do menu principal do jogo
void TelaPrincipal()
{
	// Captura o teclado
	C2D2_Botao *teclado = C2D2_PegaTeclas();
	
	// Vari�veis para o estado dos bot�es
	int jogar = BOTAO_SELECIONADO, opcoes = BOTAO_INATIVO, recordes = BOTAO_INATIVO,
		creditos = BOTAO_INATIVO, sair = BOTAO_INATIVO;

	// Controle do Menu
	int menu = 0;

	CA2_TocaMusica(mfundo, 100);

	// Repete indefinidamente
	while (estadoJogo == TELA_PRINCIPAL && !quit)
	{
		// Aqui fazemos a l�gica do menu
		//
		// Se pressionou ESC, encerra
		if (teclado[C2D2_ESC].pressionado || teclado[C2D2_ENCERRA].ativo)
		{
			quit = true;
			break;
		}

		if (teclado[C2D2_CIMA].pressionado && menu > 0){
			menu--;
			CA2_TocaEfeito(menuSobre, 0);
		}
		if (teclado[C2D2_BAIXO].pressionado && menu < 4){
			menu++;
			CA2_TocaEfeito(menuSobre, 0);
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
					   CA2_TocaEfeito(menuEscolhe, 0);
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
						CA2_TocaEfeito(menuEscolhe, 0);
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
						CA2_TocaEfeito(menuEscolhe, 0);
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
						CA2_TocaEfeito(menuEscolhe, 0);
						quit = true;	
					}
					break;
		}
		// Determina o estado dos bot�es
		/*if (menu == 0){
			
		}
		else
			jogar = BOTAO_INATIVO;
		
		if (teclado[C2D2_BAIXO].pressionado || teclado[C2D2_BAIXO].ativo)
		{
			if (opcoes == BOTAO_INATIVO)
			{
				opcoes = BOTAO_RECEMSELECIONADO;
				CA2_TocaEfeito(menuSobre, 0);
			}
			else
				opcoes = BOTAO_SELECIONADO;
			if (teclado[C2D2_ENTER].pressionado)
			{
				CA2_TocaEfeito(menuEscolhe, 0);
				estadoJogo = TELA_OPCOES;
			}
		}
		else
			opcoes = BOTAO_INATIVO;

		if (C2D2_ColidiuSprites(cursor, 0, mouse->x, mouse->y, botaoOpcoes, 1, 450, 350))
		{
			if (opcoes == BOTAO_INATIVO)
			{
				opcoes = BOTAO_RECEMSELECIONADO;
				CA2_TocaEfeito(menuSobre, 0);
			}
			else
				opcoes = BOTAO_SELECIONADO;
			if (mouse->botoes[C2D2_MESQUERDO].pressionado)
			{
				CA2_TocaEfeito(menuEscolhe, 0);
				estadoJogo = TELA_OPCOES;
			}
		}
		else
			opcoes = BOTAO_INATIVO;
		if (C2D2_ColidiuSprites(cursor, 0, mouse->x, mouse->y, botaoRecordes, 1, 150, 420))
		{
			if (recordes == BOTAO_INATIVO)
			{
				recordes = BOTAO_RECEMSELECIONADO;
				CA2_TocaEfeito(menuSobre, 0);
			}
			else
				recordes = BOTAO_SELECIONADO;
			if (mouse->botoes[C2D2_MESQUERDO].pressionado)
			{
				CA2_TocaEfeito(menuEscolhe, 0);
				estadoJogo = TELA_RECORDES;
			}
		}
		else
			recordes = BOTAO_INATIVO;
		if (C2D2_ColidiuSprites(cursor, 0, mouse->x, mouse->y, botaoCreditos, 1, 450, 420))
		{
			if (creditos == BOTAO_INATIVO)
			{
				creditos = BOTAO_RECEMSELECIONADO;
				CA2_TocaEfeito(menuSobre, 0);
			}
			else
				creditos = BOTAO_SELECIONADO;
			if (mouse->botoes[C2D2_MESQUERDO].pressionado)
			{
				CA2_TocaEfeito(menuEscolhe, 0);
				estadoJogo = TELA_CREDITOS;
			}
		}
		else
			creditos = BOTAO_INATIVO;
		if (C2D2_ColidiuSprites(cursor, 0, mouse->x, mouse->y, botaoSair, 1, 300, 490))
		{
			if (sair == BOTAO_INATIVO)
			{
				sair = BOTAO_RECEMSELECIONADO;
				CA2_TocaEfeito(menuSobre, 0);
			}
			else
				sair = BOTAO_SELECIONADO;
			if (mouse->botoes[C2D2_MESQUERDO].pressionado)
			{
				CA2_TocaEfeito(menuEscolhe, 0);
				quit = true;
			}
		}
		else
			sair = BOTAO_INATIVO;

*/

		// Aqui fazemos o desenho do menu
		C2D2_LimpaTela();
		// DEsenha o titulo
		C2D2_DesenhaSprite(titulo, 0, 0, 0);
		// DEsenha os bot�es
		if (jogar == BOTAO_INATIVO)
			C2D2_DesenhaSprite(botaoJogar, 0, 412, 300);
		else
			C2D2_DesenhaSprite(botaoJogar, 1, 412, 300);
		if (opcoes == BOTAO_INATIVO)
			C2D2_DesenhaSprite(botaoOpcoes, 0, 412, 350);
		else
			C2D2_DesenhaSprite(botaoOpcoes, 1, 412, 350);
		if (recordes == BOTAO_INATIVO)
			C2D2_DesenhaSprite(botaoRecordes, 0, 412, 400);
		else
			C2D2_DesenhaSprite(botaoRecordes, 1, 412, 400);
		if (creditos == BOTAO_INATIVO)
			C2D2_DesenhaSprite(botaoCreditos, 0, 412, 450);
		else
			C2D2_DesenhaSprite(botaoCreditos, 1, 412, 450);
		if (sair == BOTAO_INATIVO)
			C2D2_DesenhaSprite(botaoSair, 0, 412, 500);
		else
			C2D2_DesenhaSprite(botaoSair, 1, 412, 500);

		// Cr�ditos b�sicos
		C2D2_DesenhaTexto(fonte, 512, 700, "� 2015 por Alex Murat", C2D2_TEXTO_CENTRALIZADO);


		C2D2_Sincroniza(C2D2_FPS_PADRAO);
	}
}

// A fun��o do jogo rodando
void TelaJogo(){

	C2D2_Botao *teclado = C2D2_PegaTeclas();

	// Criao jogador e inicializa os campos
	// Ordem dos valores: tipo, x, y, dx, dy, angulo, vRotacao, xInicial, yInicial
	Personagem jogador = { NAVE, 181, 550, 0, 0, 0, 0 };

	// Desenha o retangulo pintado
	//C2D2P_RetanguloPintado(400, 160, 500, 260, 0, 0, 255);

	while (estadoJogo == TELA_JOGO && !teclado[C2D2_ESC].pressionado && !teclado[C2D2_ENCERRA].ativo)
	{
		C2D2_LimpaTela();

		DesenhaPersonagem(&jogador);
		

		// Roda a l�gica dos personagens
		//AtualizaJogador(&jogador);
		//AtualizaGeometroide(&inimigo);
		//if (tiro.tipo == TIRO)
		//	AtualizaTiro(&tiro);
		// Testa se pode atirar
		//if (mouse->botoes[C2D2_MESQUERDO].ativo)
		//	CriaTiro(&tiro, &jogador);
		// DEsenha os personagens
		//DesenhaPersonagem(&jogador);
		//DesenhaPersonagem(&inimigo);
		//if (tiro.tipo == TIRO)
		//	DesenhaPersonagem(&tiro);
		// Dsenha o cursor do mouse
		//C2D2_DesenhaSprite(cursor, 0, mouse->x, mouse->y);
		//C2D2P_RetanguloPintado(400, 160, 500, 260, 0, 0, 255);

		C2D2_Sincroniza(C2D2_FPS_PADRAO);
	}
	// Indica que deve voltar ao menu principal
	estadoJogo = TELA_PRINCIPAL;

}

void DesenhaPersonagem(Personagem *pers)
{
	// Determina o sprite que vai desenhar
	unsigned int sprite = 0;
	// Calcula o �ngulo ajustado ao desenho
	switch (pers->tipo)
	{
	case NAVE:
		sprite = spNave;
		break;
	case TIRO:
		sprite = spTiro;
		break;
	default:
		sprite = 0;
	}
	// Desenha o sprite. Note que como o personagem tem �ngulos de 45� em 45�, basta fazer
	// a divis�o por 45 para obter o quadro correto do desenho
	C2D2_DesenhaSprite(sprite, 0, pers->x, pers->y);
}

// Fun��o que mostra uma mensagem de erro do sistema
void TelaAzul()
{
	C2D2_Botao *teclado = C2D2_PegaTeclas();
	while (!teclado[C2D2_ESC].pressionado && !teclado[C2D2_ENCERRA].ativo)
	{
		C2D2_TrocaCorLimpezaTela(0, 0, 255);
		C2D2_LimpaTela();
		C2D2_DesenhaTexto(fonte, 512, 268, "Tela em desenvolvimento.", C2D2_TEXTO_CENTRALIZADO);
		C2D2_DesenhaTexto(fonte, 512, 500, "Pressione ESC para encerrar a aplica��o.", C2D2_TEXTO_CENTRALIZADO);
		C2D2_Sincroniza(C2D2_FPS_PADRAO);
	}
	// Indica que deve encerrar
	quit = true;
}

