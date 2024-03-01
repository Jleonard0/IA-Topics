#include <iostream>
#include "Item.h"
#include <vector>
#include <algorithm>

using namespace std;

void guloso(int capacidade_max)
{

    //Declaração da mochila
    int capacidade = 0;
    vector<Item> mochila;

    //Declaração de Itens
    Item item1(1, 10, 15);
    Item item2(2, 40, 90);
    Item item3(3, 26, 50);
    Item item4(4, 32, 60);
    Item item5(5, 8, 60);
    
    vector<Item> itens = {item1, item2, item3, item4, item5};
    

    sort(itens.begin(), itens.end(), [](const Item& item1, const Item& item2) 
    {
        return item1.getHeuristica() > item2.getHeuristica();
    });



    for (const auto& item : itens) 
    {
        if (item.getPeso() < capacidade_max && capacidade + item.getPeso() <= capacidade_max )
        {
            capacidade += item.getPeso();
            mochila.push_back(item);
            item.imprime_item();
        }
    }


    cout << "Na mochila temos: " << capacidade << endl;
    cout << "Capacidade Maxima: " << capacidade_max << endl;

}


int main() {
    
    guloso(80);

    return 0;
}