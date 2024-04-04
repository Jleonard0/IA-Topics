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
    Vertex* addVertex(Vertex* vertex);
    Vertex* getVertex(std::string nameVertex);
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

Vertex* Graph::addVertex(Vertex* vertex)
{
    return new Vertex("a");
}

Vertex* Graph::getVertex(std::string nameVertex)
{
    return this->vertices.find(nameVertex)->second;
}

bool Graph::addEdge(std::string nameVertexA, std::string nameVertexB, int cost)
{
    return false;
}

Graph::~Graph()
{
}

#endif