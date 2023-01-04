#include "../include/Bola.hpp"
#include <iostream>


Bola::Bola(std::vector<int> limiteX, std::vector<int> limiteY) {
    // definido o centro do campo
    this->initX = (limiteX[1] - limiteX[0]) / 2;
    this->initY = (limiteY[1] - limiteY[0]) / 2;

    this->centroCampo();

    // definido os limites da bola
    this->limiteTopo = limiteY[0];
    this->limiteBase = limiteY[1];

    this->raqJogador = limiteX[0] + 3;
    this->raqOponente = limiteX[1] - 3;
}

void Bola::imprimir() {
    posicionar(getX(), getY());
      std::cout << "0";
      std::cout.flush();
}
void Bola::posicionar(int _x, int _y) {
    std::cout << "\033[" << _y << ";" << _x << "f";
    std::cout.flush();
}

void Bola::movimento(int jogador, int oponente) {
    // movimento e si
    this->x = getX() + getVelocX();
    this->y = getY() + getVelocY();

    // colisão com parades (superior e inferior)
    if ( getY() >= limiteBase || (getY() - 1) <= limiteTopo) 
        this->velocY *= -1;

    // colisão com raquete do jogador
    if( getX() <= raqJogador &&                         // posição x da raquete
        getY() >= jogador && getY() < jogador+6 &&     // altura da raquete
        velocX < 0)                                     // direção correta do acionamento
        this->velocX *= -1;

    // colisão com raquete do oponente
    if( getX() >= raqOponente &&                        // posição x da raquete
        getY() >= oponente && getY() < oponente+6 &&   // altura da raquete
        velocX > 0)                                     // direção correta do acionamento
        this->velocX *= -1;


}

void Bola::centroCampo() {
    this->x = this->initX;
    this->y = this->initY;
}

int Bola::getX() const {
    return this->x;
}
int Bola::getY() const {
    return this->y;
}
int Bola::getVelocX() const {
    return this->velocX;
}
int Bola::getVelocY() const {
    return this->velocY;
}