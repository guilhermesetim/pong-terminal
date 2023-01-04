#ifdef _WIN32
#include <windows.h>
#include <conio.h>
#include <iostream>

#elif defined (unix)
#include <iostream>
#include <termios.h>
#include <unistd.h>
#include <fcntl.h>
#endif

#include "../include/acaoTeclado.hpp"

int getch()
{
   #if defined (_WIN32)
   return _getch();
   #elif defined (unix)
   struct termios oldTerminal, newTerminal;
   int ch;
   tcgetattr(STDIN_FILENO, &oldTerminal); //pega atts da STDIN_FILENO
   newTerminal = oldTerminal;
   newTerminal.c_lflag &= ~(ICANON | ECHO); //desabilita echo e canonical mode
   tcsetattr(STDIN_FILENO, TCSANOW, &newTerminal); //seta agora
   ch = getchar(); //le char
   tcsetattr(STDIN_FILENO, TCSANOW, &oldTerminal); //seta antigo
   return ch;
   #endif
}


int kbhit()
{
   #if defined (_WIN32)
   return _kbhit();
   #elif defined (unix)
   struct termios oldTerminal, newTerminal;
   int ch;
   int oldFile;
   tcgetattr(STDIN_FILENO, &oldTerminal); //pega atributos da STDIN_FILENO e coloca na oldt
   newTerminal = oldTerminal;
   newTerminal.c_lflag &= ~(ICANON | ECHO); //desabilita echo e canonical mode

   tcsetattr(STDIN_FILENO, TCSANOW, &newTerminal); //seta newt na STDIN_FILENO agora(TCSANOW)

   oldFile = fcntl(STDIN_FILENO, F_GETFL, 0); //fcntl manipulacao de descriptors de arquivos
         //F_GETFL pega as flags de STDIN_FILENO, zero pois F_GETFL � void
   fcntl(STDIN_FILENO, F_SETFL, oldFile | O_NONBLOCK);
      //F_SETFL seta as flags do terceiro argumento em STDIN_FILENO
      //O_NONBLOCK nao deixa as slow system calls(no caso read) travar o I/O esperando uma entrada

   ch = getchar(); //le o prox char da stdin

   tcsetattr(STDIN_FILENO, TCSANOW, &oldTerminal); //seta antigo
   fcntl(STDIN_FILENO, F_SETFL, oldFile); //seta antigo

   if(ch != EOF)
   {
      ungetc(ch, stdin); //coloca ch de volta na stdin
      return 1;
   }
   return 0;
   #endif
}
