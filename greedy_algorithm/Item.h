#ifndef ITEM_H
#define ITEM_H

#include <iostream>

using namespace std;

class Item {
private:
    int id;
    int peso;
    int valor;
    double heuristica;

public:
    Item();
    Item(int id, int peso, int valor);
    ~Item();

    
    int getId() const;
    int getPeso() const;
    int getValor() const;
    double getHeuristica() const;

    void setId(int newId);
    void setPeso(int newPeso);
    void setValor(int newValor);

    int f_heuristica();
    void imprime_item() const;
};

#endif
