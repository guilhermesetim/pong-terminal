#include "../include/acaoTeclado.hpp"
#include "../include/Ambiente.hpp"
#include "../include/Placar.hpp"
#include "../include/Raquete.hpp"
#include "../include/Bola.hpp"


using namespace std;

int main() {

   Ambiente ambiente(0,82,0,24);
   ambiente.cursor(false);

   Bola bola(ambiente.limitesX(), ambiente.limitesY());

   Raquete jogador(ambiente.getInicioX()+1, ambiente.limitesY());
   Raquete oponente(ambiente.getFimX()-1, ambiente.limitesY());

   Placar placar(ambiente.limitesX());


   /*      Jogo        */
   while (placar.getJogador() < 3 && placar.getOponente()  < 3) {

      ambiente.limparTela();

      // impressões na tela
      ambiente.imprimir();
      placar.imprimir();
      jogador.imprimir();
      oponente.imprimir();
      bola.imprimir();

     

      // movimentação raquetes
      if( kbhit() ) {
         char tecla = getch();
         if ( tecla == 65 ) jogador.subir();    // 65 = Seta para cima tabela ASCII
         if ( tecla == 66 ) jogador.descer();   // 66 = Seta para baixo tabela ASCII
      }

      oponente.movimentoAutonomo();

      bola.movimento(jogador.getY(), oponente.getY());   


      if (placar.pontoJogador(bola.getX())){
         placar.addJogador();
         bola.centroCampo();
      } 
      if (placar.pontoOponente(bola.getX())) {
         placar.addOponente();
         bola.centroCampo();
      }

      ambiente.tempoJogo(100);

   }

   ambiente.limparTela();
   ambiente.cursor(true);

   return 0;
}

