#include "../include/Ambiente.hpp"

#include <iostream>
#include <termios.h>



Ambiente::Ambiente(int iX, int fX, int tY, int bY) {
    this->inicioX = iX;
    this->fimX = fX;
    this->topoY = tY;
    this->baseY = bY;
}


void Ambiente::imprimir() {
    // meio campo
    for(int i = 1 ; i < 25; ++i) {
        posicionar(40, i);
        std::cout << "|";
    }
    std::cout.flush();
}

void Ambiente::posicionar(int _x, int _y) {

    std::cout << "\033[" << _y << ";" << _x << "f";
    std::cout.flush();
}

void Ambiente::limparTela() {
   #if defined (_WIN32)
   system("cls");
   #elif defined (unix)
   std::cout << "\033[2J\033[0;0f"; //2J apaga tela, o;of posiciona cursor na linha 0; coluna 0
   #endif
   return;
}

void Ambiente::cursor(bool _liga)
{
   #if defined (_WIN32)
   HANDLE output = GetStdHandle(STD_OUTPUT_HANDLE);
   CONSOLE_CURSOR_INFO cursor;
   GetConsoleCursorInfo(output, &cursor);
   cursor.bVisible = _liga;
   SetConsoleCursorInfo(output, &cursor);
   #elif defined (unix)
    static struct termios oldTerminal;
    static struct termios newTerminal;
   if(!_liga) {
    /*Cursor em si*/
        std::cout << "\033[?25l"; //25 visibilidade cursor, l reset mode
    
    /*echo*/
        tcgetattr (0, &oldTerminal); //zero=STDIN_FILENO
        newTerminal = oldTerminal;
        newTerminal.c_lflag &= ~(ECHO | ICANON); //desabilita echo e canonical mode
        newTerminal.c_cc[VMIN] = 1; //read retorna quando VMIN(1) bytes de leitura for atingido
        newTerminal.c_cc[VTIME] = 0;
        tcsetattr(0, TCSAFLUSH, &newTerminal); //seta atts
   }
   else {
    /*Cursor em si*/
        std::cout << "\033[?25h"; //25 visibilidade cursor, h set mode

    /*echo*/
        tcsetattr(0, TCSAFLUSH, &oldTerminal); //seta antigo
   }
   #endif
}


void Ambiente::tempoJogo(long int _tempo)
{
    #if defined (_WIN32)
    Sleep(_tempo);
    #elif defined (unix)
    long segundos = _tempo/1000;
    _tempo -= (segundos * 1000);

    struct timespec* req = (struct timespec*) new struct timespec;

    req->tv_sec = segundos;
    req->tv_nsec = _tempo * 1000000;

    nanosleep(req, NULL);
    delete req;
    #endif
}

int Ambiente::getInicioX() const {
    return this->inicioX;
}
int Ambiente::getFimX() const {
    return this->fimX;
}
int Ambiente::getTopoY() const {
    return this->topoY;
}
int Ambiente::getBaseY() const {
    return this->baseY;
}
std::vector<int> Ambiente::limitesY()  {

    std::vector<int> limite;

    limite.push_back(getTopoY());
    limite.push_back(getBaseY());

    return limite;
}

std::vector<int> Ambiente::limitesX()  {

    std::vector<int> limite;

    limite.push_back(getInicioX());
    limite.push_back(getFimX());

    return limite;
}