#pragma once

#include <vector>
#include <algorithm>
#include <map>
#include <queue>

#include "graph.h"
#include "edge.h"
#include "airport.h"
using namespace std;

typedef string Vertex;

class dijkstra {
    public:
        dijkstra(Graph g, Vertex start, Vertex end);
        map<Vertex, double> distance;
        double actual_distance;
        map<Vertex, Vertex> path;
        vector<Vertex> visited;
        std::string state;
        void print(Graph g, Vertex start, Vertex end, string fileName);

    private:
        Graph g_;
        Vertex start_;
        Vertex end_;
};