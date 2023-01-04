#include <vector>
class Bola {
private:
    int x;
    int y;
    int velocX = 2;
    int velocY = 1;
    int initX;
    int initY;
    int raqJogador;
    int raqOponente;
    int limiteTopo;
    int limiteBase;
    void posicionar(int, int);

public:
    Bola(std::vector<int>, std::vector<int>);
    void imprimir();
    void movimento(int, int);
    int getX() const;
    int getY() const;
    int getVelocX() const;
    int getVelocY() const;
    void centroCampo();
};