/**
Classe  : Jogo
Objetivo: Controla o jogo - Invocação dos anjos/demônios, controle da nave e pontuação
**/
#include "Controlador.h"
#include "Nave.h"

const long MAX    = 8;		//Número máximo de anjos/demônios na tela
const long LIMITE = 0;		//Destino final dos anjos/demônios na tela

class Jogo
{
   private:
      Controlador *lista[MAX];	//Lista de anjos e demônios vivos na tela
	  Nave *MinhaNave;			//Minha Nave (Superior)
	  Nave *MinhaNave2;			//Minha Nave (Inferior)
      long pontuacao;		//Para saber o lado que esta vencendo e quem venceu no final

   public:
      Jogo();

      void executar();

   private:
      bool verificar();
      void criar();
	  void criarNaves();
      void desenhar();
	  void abrirjogo();
	  void finalizarjogo(bool vitoria);

};