
class Recursos{

public:

	// Música do demo
	unsigned int mfundo = 0;

	// Variáveis para os recursos visuais do jogo
	unsigned int fonte = 0;
	unsigned int titulo = 0;
	unsigned int cursor = 0;

	// Variaveis dos botoes do menu principal
	unsigned int botaoJogar = 0, botaoRecordes = 0, botaoOpcoes = 0, botaoCreditos = 0, botaoSair = 0;

	// Carrega os arquivos do jogo
	char nome[512], diretorio[64];
	// Escolhe o diretório base dos recursos

	// Variáveis para os personagens
	unsigned int spNave = 0, spTiro = 0, spGeomPeq1 = 0, spNave2 = 0;

	// Variáveis do cenário
	unsigned int spFundo = 0;

	// Variáveis para os recursos de áudio do jogo
	unsigned int menuSobre = 0;
	unsigned int menuEscolhe = 0;
	unsigned int jogoTiro = 0;

	void CarregaRecursos();
	void RemoveRecursos();

};