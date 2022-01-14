#pragma once

#include "graph.h"

using namespace std;

class Kruskal {
    public:
        pair<vector<Edge>, int> kruskal_mst(Graph airport);
        void print(Graph aiport, string filename);
};

class DSU {
    public:
        DSU (vector<Edge> edges) {
            for (auto edge: edges) {
                parent[edge.weight] = -1;
                rank[edge.weight] = 1;
            }
        }

        int find (int dist) {
            if (parent[dist] != -1) {
                return dist;
            }
            return parent[dist] = find(parent[dist]);
        }

        void unite (int x, int y) {
            int s1 = find(x);
            int s2 = find(y);

            if (s1 != s2) {
                if (rank[s1] < rank[s2]) {
                    parent[s1] = s2;
                    rank[s2] += rank[s1];
                } else {
                    parent[s2] = s1;
                    rank[s1] += rank[s2];
                }
            }
        }
        unordered_map<int, int> parent;
        unordered_map<int, int> rank;
};