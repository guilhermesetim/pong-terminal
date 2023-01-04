#include <vector>
class Placar {
private:
    int jogador = 0;
    int oponente = 0;
    int inicioCampo;
    int fimCampo;
    void posicionar(int, int);

public:
    Placar(std::vector<int>);
    int getJogador();
    int getOponente();
    void addJogador();
    void addOponente();
    void imprimir();
    bool pontoJogador(int);
    bool pontoOponente(int);
};