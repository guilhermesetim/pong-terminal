#include <vector>

class Ambiente {
private:
    int inicioX;
    int fimX;
    int topoY;
    int baseY;
    void posicionar(int, int);
public:
    Ambiente(int,int,int,int);
    void limparTela();
    void cursor(bool);
    void imprimir();
    void tempoJogo(long int);
    int getInicioX() const;
    int getFimX() const;
    int getTopoY() const;
    int getBaseY() const;
    std::vector<int> limitesY();
    std::vector<int> limitesX();
};

