#ifndef GRAPH_H
#define GRAPH_H

#include <map>
#include <Vertex.hpp>

class Graph
{
private:
    std::map<std::string, Vertex *> vertices;

public:
    Graph();
    int numVertices();
    Vertex *addVertex(Vertex *vertex);
    Vertex *getVertex(std::string nameVertex);
    bool isVertex(std::string nameVertex);
    bool addEdge(std::string nameVertexA, std::string nameVertexB, int cost);
    ~Graph();
};

Graph::Graph()
{
}

int Graph::numVertices()
{
    return this->vertices.size();
}

Vertex *Graph::addVertex(Vertex *vertex)
{
    return this->vertices[vertex->getName()] = vertex;
}

bool Graph::isVertex(std::string nameVertex)
{
    std::map<std::string, Vertex *>::key_compare keycomp = this->vertices.key_comp();

    for (auto i : this->vertices)
    {
        if (!keycomp(i.first, nameVertex))
        {
            return true;
        }
    }
    return false;
}

Vertex *Graph::getVertex(std::string nameVertex)
{
    if (!this->isVertex(nameVertex))
    {
        return NULL;
    }
    return this->vertices[nameVertex];
}

bool Graph::addEdge(std::string nameVertexA, std::string nameVertexB, int cost)
{
    if (this->vertices.size() < 2 || !this->isVertex(nameVertexA) || !this->isVertex(nameVertexB))
    {
        return false;
    }
    this->vertices[nameVertexA]->addChild(this->vertices[nameVertexB], cost);
    this->vertices[nameVertexB]->addChild(this->vertices[nameVertexA], cost);
    return true;
}

Graph::~Graph()
{
}

#endif