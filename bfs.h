#pragma once
#include "graph.h"
#include "airport.h"

using namespace std;

class bfs{
    public:
        list<Vertex> traversal(Graph &graph, Vertex originalAirport);
        void print(Graph &graph, Vertex originalPoint, string FileName);
        list<Vertex> orderOfTraversal;
};