// SuperSoulWings.cpp : Defines the entry point for the console application.
//

// Chamar cabeçalho
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

	// Inicia o áudio
	CA2_Inicia();

	// Carrega os recursos do jogo
	CarregaRecursos();

	// A repetição principal do jogo
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

	// Variáveis para animar o personagem
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

// A função do menu principal do jogo
void TelaPrincipal()
{
	// Captura o teclado
	C2D2_Botao *teclado = C2D2_PegaTeclas();
	
	// Variáveis para o estado dos botões
	int jogar = BOTAO_SELECIONADO, opcoes = BOTAO_INATIVO, recordes = BOTAO_INATIVO,
		creditos = BOTAO_INATIVO, sair = BOTAO_INATIVO;

	// Controle do Menu
	int menu = 0;

	CA2_TocaMusica(mfundo, 100);

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
		

		// Aqui fazemos o desenho do menu
		C2D2_LimpaTela();
		// DEsenha o titulo
		C2D2_DesenhaSprite(titulo, 0, 0, 0);
		// DEsenha os botões
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

		// Créditos básicos
		C2D2_DesenhaTexto(fonte, 512, 700, "© 2015 por Alex Murat", C2D2_TEXTO_CENTRALIZADO);


		C2D2_Sincroniza(C2D2_FPS_PADRAO);
	}
}

// A função do jogo rodando
void TelaJogo(){

	C2D2_Botao *teclado = C2D2_PegaTeclas();
	clock_t tInicio, tFim, tDecorrido, tInicio2, tFim2, tDecorrido2;
	int tflag = 0, tflag2 = 0;

	// Criao jogador e inicializa os campos
	// Ordem dos valores: tipo, x, y, dx, dy, angulo, vRotacao, xInicial, yInicial
	Personagem jogador = { NAVE, 209, 600, 0, 0, 0, 0 };

	// Desenha o retangulo pintado
	//C2D2P_RetanguloPintado(400, 160, 500, 260, 0, 0, 255);

	while (estadoJogo == TELA_JOGO && !teclado[C2D2_ESC].pressionado && !teclado[C2D2_ENCERRA].ativo)
	{
		C2D2_LimpaTela();
		C2D2_DesenhaSprite(spFundo, 0, 0, 0);

		DesenhaPersonagem(&jogador);
		
		if(teclado[C2D2_ESQUERDA].ativo)
			jogador.x = jogador.x - 1;
		if (teclado[C2D2_DIREITA].ativo)
			jogador.x = jogador.x + 1;
		if (teclado[C2D2_CIMA].ativo)
			jogador.y = jogador.y - 1;
		if (teclado[C2D2_BAIXO].ativo)
			jogador.y = jogador.y + 1;

		if (teclado[C2D2_ESQUERDA].pressionado){
			
			if (tflag == 0){
				tInicio = clock();
				tflag = 1;
			}
			else{
				tFim = clock();
				tDecorrido = ((double)(tFim - tInicio)) / (CLOCKS_PER_SEC / 1000);
				if (tDecorrido < 750)
					jogador.x = jogador.x - 40;
				tflag = 0;
			}
		}

		if (teclado[C2D2_DIREITA].pressionado){

			if (tflag2 == 0){
				tInicio2 = clock();
				tflag2 = 1;
			}
			else{
				tFim2 = clock();
				tDecorrido2 = ((double)(tFim2 - tInicio2)) / (CLOCKS_PER_SEC / 1000);
				if (tDecorrido2 < 750)
					jogador.x = jogador.x + 40;
				tflag2 = 0;
			}
		}
		

		// Roda a lógica dos personagens
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
		//C2D2P_RetanguloPintado(10, 20, 30, 40, 1, 125, 125);

		C2D2_Sincroniza(C2D2_FPS_PADRAO);
	}
	// Indica que deve voltar ao menu principal
	estadoJogo = TELA_PRINCIPAL;

}

void DesenhaPersonagem(Personagem *pers)
{
	// Determina o sprite que vai desenhar
	unsigned int sprite = 0;
	// Calcula o ângulo ajustado ao desenho
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
	// Desenha o sprite. Note que como o personagem tem ângulos de 45º em 45º, basta fazer
	// a divisão por 45 para obter o quadro correto do desenho
	C2D2_Botao *teclado = C2D2_PegaTeclas();

	if (teclado[C2D2_ESQUERDA].ativo)
			C2D2_DesenhaSprite(sprite, 3, pers->x, pers->y);
	else if (teclado[C2D2_DIREITA].ativo)
			C2D2_DesenhaSprite(sprite, 6, pers->x, pers->y);
	else
		C2D2_DesenhaSprite(sprite, 0, pers->x, pers->y);
}

// Função que mostra uma mensagem de erro do sistema
void TelaAzul()
{
	C2D2_Botao *teclado = C2D2_PegaTeclas();
	while (!teclado[C2D2_ESC].pressionado && !teclado[C2D2_ENCERRA].ativo)
	{
		C2D2_TrocaCorLimpezaTela(0, 0, 255);
		C2D2_LimpaTela();
		C2D2_DesenhaTexto(fonte, 512, 268, "Tela em desenvolvimento.", C2D2_TEXTO_CENTRALIZADO);
		C2D2_DesenhaTexto(fonte, 512, 500, "Pressione ESC para encerrar a aplicação.", C2D2_TEXTO_CENTRALIZADO);
		C2D2_Sincroniza(C2D2_FPS_PADRAO);
	}
	// Indica que deve encerrar
	quit = true;
}

