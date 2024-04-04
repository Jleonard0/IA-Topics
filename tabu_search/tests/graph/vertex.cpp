#include <catch.hpp>
#include "../../src/libs/Vertex.hpp"

TEST_CASE( "Test class Node", "[single-file]" ) {
  
  SECTION("crete vertex")
  {
    Vertex *a = new Vertex("a");
    
    REQUIRE(a->getName() == "a");
  }

  SECTION("method getCostToGoTo")
  {
    Graph *graph = new Graph();
    Vertex *a = new Vertex("a");
    Vertex *b = new Vertex("b");
    Vertex *c = new Vertex("c");
    
    graph->addVertex(a);
    graph->addVertex(b);
    graph->addVertex(c);
    
    graph->addEdge("a", "b", 10);
    graph->addEdge("b", "c", 11);

    REQUIRE(graph->getVertex("a")->getCostToGoTo("b") == 10);
    REQUIRE(graph->getVertex("a")->getCostToGoTo("c") == -1);
    REQUIRE(graph->getVertex("b")->getCostToGoTo("a") == 10);
    REQUIRE(graph->getVertex("b")->getCostToGoTo("c") == 11);
    REQUIRE(graph->getVertex("c")->getCostToGoTo("a") == -1);
  }

  SECTION("method getChildVertex")
  {
    Graph *graph = new Graph();
    Vertex *a = new Vertex("a");
    Vertex *b = new Vertex("b");
    
    graph->addVertex(a);
    graph->addVertex(b);
    
    REQUIRE(graph->addEdge("a", "b", 10) == true);

    REQUIRE(graph->getVertex("a")->getChildVertex("b") == b);
  }
}

