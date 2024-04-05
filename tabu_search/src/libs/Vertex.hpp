#ifndef NODE_H
#define NODE_H

#include <map>
#include <string>
#include <utility>
#include "Graph.hpp"

class Vertex
{
protected:
    std::map<std::string, std::pair<int, Vertex *> *> childVertices;
    bool addChild(Vertex *vertex, int cost);
    bool removeChild(std::string name);

private:
    std::string name;

public:
    Vertex(std::string name);
    std::string getName();
    bool isChildVertex(std::string nameVertex);
    Vertex *getChildVertex(std::string nameVertex);
    int getCostToGoTo(std::string nameVertex);
    ~Vertex();
    friend class Graph;
};

Vertex::Vertex(std::string name)
{
    this->name = name;
}

std::string Vertex::getName()
{
    return this->name;
}

bool Vertex::addChild(Vertex *vertex, int cost)
{
    if (this->isChildVertex(vertex->getName()))
    {
        return false;
    }
    auto aux = new std::pair<int, Vertex *>(cost, vertex);
    this->childVertices[vertex->getName()] = aux;
    return true;
}

bool Vertex::isChildVertex(std::string nameVertex)
{
    std::map<std::string, std::pair<int, Vertex *> *>::key_compare keycomp = this->childVertices.key_comp();
    for (auto i : this->childVertices)
    {
        if (!keycomp(i.first, nameVertex))
        {
            return true;
        }
    }
    return false;
}

Vertex *Vertex::getChildVertex(std::string nameVertex)
{
    if (!this->isChildVertex(nameVertex))
    {
        return NULL;
    }
    return this->childVertices[nameVertex]->second;
}

int Vertex::getCostToGoTo(std::string nameVertex)
{
    if (!this->isChildVertex(nameVertex))
    {
        return -1;
    }
    const int aux = this->childVertices[nameVertex]->first;
    return aux;
}

Vertex::~Vertex()
{
}

#endif