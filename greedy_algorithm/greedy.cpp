#include <iostream>
#include "Item.h"

void mochila(Item, int peso)
{

}


int main() {
    
    Item item2(0, 10, 15); // Usa o construtor com parâmetros
    item2.f_heuristica();
    std::cout << "Item: ID = " << item2.getId() << ", Peso = " << item2.getPeso() << ", Valor = " << item2.getValor() << ", Heuristica = " << item2.getHeuristica() << std::endl;

    return 0;
}