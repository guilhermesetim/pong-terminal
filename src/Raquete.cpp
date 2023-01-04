#include "../include/Raquete.hpp"

#include <iostream>


Raquete::Raquete(int inicial_X, std::vector<int> limiteY) {
    // inicio da raquete
    this->setX(inicial_X);
    int _inicial_Y = (((limiteY[1] - limiteY[0]) / 2) - (getTamanho()/2));
    this->setY(_inicial_Y);

    // limite da raquete
    this->definirLimite(limiteY);
}

void Raquete::definirLimite(std::vector<int> limite) {
    this->limiteTopo = limite[0];
    this->limiteBase = limite[1];
}

void Raquete::posicionar(int _x, int _y) {
    std::cout << "\033[" << _y << ";" << _x << "f";
    std::cout.flush();
}

void Raquete::imprimir() {
    for(int i = 0; i < getTamanho(); ++i) {
            posicionar(getX(), getY()+i);
            std::cout << "|";
        }
        std::cout.flush();
}


void Raquete::subir() {
    int _novaPos = getY() - 3;
    int posValidada = verificarLimiteTopo(_novaPos);
    this->setY(posValidada);
}
int Raquete::verificarLimiteTopo(int valor) {
    if ( valor < this->limiteTopo ) 
        return (this->limiteTopo + 1);
    else 
        return valor;   
}


void Raquete::descer() {
    int _novaPos = getY() +  3;
    int posValidada = verificarLimiteBase(_novaPos);
    this->setY(posValidada);
}
int Raquete::verificarLimiteBase(int valor) {
    if ( baseRaquete() >= this->limiteBase) 
        return (this->limiteBase - 6);
    else 
        return valor;   
}

int Raquete::baseRaquete() {
    int _base = getY()+6;
    return _base;
}

int Raquete::getTamanho() const {
    return this->tamanho;
}

int Raquete::getX() const {
    return this->x;
}
void Raquete::setX(int posX) {
    this->x = posX;
}

int Raquete::getY() const {
    return this->y;
}
void Raquete::setY(int posY) {
    this->y = posY;
}
