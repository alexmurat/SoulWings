#include "Recursos.h"

// Telas do Menu do jogo
enum { TELA_PRINCIPAL, TELA_JOGO, TELA_OPCOES, TELA_CREDITOS, TELA_RECORDES };

// Estados de um botão
enum { BOTAO_INATIVO, BOTAO_RECEMSELECIONADO, BOTAO_SELECIONADO };

class Jogo
{

public:
	Jogo();
	int estadoJogo;
	bool quit;
	void MenuInicial();
	Recursos rc;

private:
	void TelaPrincipal();
	void TelaJogo();
	void TelaAzul();

	//bool verificar();
	//void criar();
	//void criarNaves();
	//void desenhar();
	//void abrirjogo();
	//void finalizarjogo(bool vitoria);

};