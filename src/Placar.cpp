#include "../include/Placar.hpp"

#include <iostream>
#include <vector>

Placar::Placar(std::vector<int> limite) {
    this->inicioCampo = limite[0];
    this->fimCampo = limite[1];
}


/*  Jogador (esquerda)  */
int Placar::getJogador() {
    return this->jogador;
}
void Placar::addJogador() {
    this->jogador++;
}
bool Placar::pontoJogador(int bola) {
    if(bola <= this->inicioCampo) 
        return true;
    else
        return false;
}

/*  Oponente (direita)  */
int Placar::getOponente() {
    return this->oponente;
}

void Placar::addOponente() {
    this->oponente++;
}

bool Placar::pontoOponente(int bola) {
    if(bola >= this->fimCampo) 
        return true;
    else
        return false;
}

void Placar::posicionar(int _x, int _y) {
    std::cout << "\033[" << _y << ";" << _x << "f";
    std::cout.flush();
}

void Placar::imprimir() {
     // placar
    posicionar(18, 2);
    std::cout << jogador;
    posicionar(58, 2);
    std::cout << oponente;
}


