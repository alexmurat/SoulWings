/**
Classe  : Controlador
Objetivo: Controla as ações dos anjos/demonios (movimento e impressão)
**/

const long INICIO = 78;	//Posição horizontal inicial dos anjos/demonios
const long PASSO  = 5;	//Constante para se basear na velocidade média dos anjos/demonios

class Controlador
{
   private:
      long x,y;    //Coordenadas do anjo/demonio
      long limite; //limite direito
      long cor;    //Anjos Brancos e Demonios Vermelhos
      long passo;  //velocidade do passo do anjo/demonio

   public:
      Controlador(long limite);
      ~Controlador();

      void desenhar();
      bool mover();
      void apagar();

	  long getx() { return x; }
	  long gety() { return y; }
      
};