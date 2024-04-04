#ifndef NODE_H
#define NODE_H

#include <map>
#include <string>
#include <utility>
#include "Graph.hpp"

class Vertex
{
protected:
    std::map<std::string, std::pair<int, Vertex*>> childVertices;
    bool addChild(Vertex vertex, int cost);
    bool removeChild(std::string name);
private:
    std::string name;
public:
    Vertex(std::string name);
    std::string getName();
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

Vertex * Vertex::getChildVertex(std::string nameVertex)
{
    return this->childVertices.find("nameVertex")->second.second;
}

int Vertex::getCostToGoTo(std::string nameVertex)
{
    return -1;
}

Vertex::~Vertex()
{
}

#endif