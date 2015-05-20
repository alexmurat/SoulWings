/**
Classe  : Controlador
Objetivo: Controla as a��es dos anjos/demonios (movimento e impress�o)
**/

const long INICIO = 78;	//Posi��o horizontal inicial dos anjos/demonios
const long PASSO  = 5;	//Constante para se basear na velocidade m�dia dos anjos/demonios

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