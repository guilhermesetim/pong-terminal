#include <vector>

class Raquete {
private:
    int x;
    int y;
    int limiteTopo;
    int limiteBase;
    int tamanho = 7;
    
public:
    Raquete(int, std::vector<int>);
    void definirLimite(std::vector<int>);
    void imprimir();
    void subir();
    void descer();
    int baseRaquete();
    int getX() const;
    void setX(int);
    int getY() const;
    void setY(int);
    int getTamanho() const;
private:
    void posicionar(int, int);
    int verificarLimiteTopo(int);
    int verificarLimiteBase(int);
};