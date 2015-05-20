/**
Classe  : Jogo
Objetivo: Controla o jogo - Invoca��o dos anjos/dem�nios, controle da nave e pontua��o
**/
#include "Controlador.h"
#include "Nave.h"

const long MAX    = 8;		//N�mero m�ximo de anjos/dem�nios na tela
const long LIMITE = 0;		//Destino final dos anjos/dem�nios na tela

class Jogo
{
   private:
      Controlador *lista[MAX];	//Lista de anjos e dem�nios vivos na tela
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