#include "Item.h"


Item::Item() : id(0), peso(0), valor(0) {}

Item::Item(int id, int peso, int valor) : id(id), peso(peso), valor(valor) 
{
    this->f_heuristica();
}


int Item::getId() const { return id; }
int Item::getPeso() const { return peso; }
int Item::getValor() const { return valor;}
double Item::getHeuristica() const { return heuristica;}


void Item::setId(int newId) { id = newId; }
void Item::setPeso(int newPeso) { peso = newPeso; }
void Item::setValor(int newValor) { valor = newValor; }

int Item::f_heuristica()
{
    this->heuristica = (this->peso*2+this->valor*3)/5;
}