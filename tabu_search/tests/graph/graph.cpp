#include <catch.hpp>
#include "../../src/libs/Graph.hpp"

TEST_CASE("Test class Graph", "[single-file]")
{
  SECTION("create graph")
  {
    Graph *test = new Graph();
    
    REQUIRE(test->numVertices() == 0);
  }

  SECTION("add vetices to the graph")
  {
    Graph *graph = new Graph();
    Vertex *a = new Vertex("a");
    Vertex *b = new Vertex("b");
    
    REQUIRE(graph->numVertices() == 0);
    
    graph->addVertex(a);
    graph->addVertex(b);

    REQUIRE(graph->getVertex("a") == a );
    REQUIRE(graph->getVertex("b") == b );
    
    REQUIRE(graph->numVertices() == 2);
  }

  SECTION("add edges to graph and check integrity")
  {
    Graph *graph = new Graph();
    Vertex *a = new Vertex("a");
    Vertex *b = new Vertex("b");
    
    graph->addVertex(a);
    graph->addVertex(b);
    
    REQUIRE(graph->addEdge("a", "b", 10) == true);
    
    REQUIRE(graph->getVertex("a")->getChildVertex("b") == b);
    REQUIRE(graph->getVertex("b")->getChildVertex("a") == a);
  }
}