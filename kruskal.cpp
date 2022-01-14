#include "kruskal.h"
#include <string>
#include <iostream>

using namespace std;

pair<vector<Edge>, int> Kruskal::kruskal_mst(Graph airport) {
    vector<Edge> edges = airport.getEdges();
    sort(edges.begin(), edges.end());
    
    unordered_map<string, int> nums;
    int count = 0;
    for (auto i: edges) {
        pair<string, int> source(i.source, count);
        count++;
        nums.insert(source);
        
        pair<string, int> dest(i.dest, count);
        count++;
        nums.insert(dest);
    }

    int length = 0;
    vector<Edge> MST;
    DSU dsj_set(edges);
    for (auto edge : edges) {
        if (dsj_set.find(nums[edge.source]) != dsj_set.find(nums[edge.dest])) {
            dsj_set.unite(nums[edge.source], nums[edge.dest]);
            length += edge.weight;
            MST.insert(MST.begin(), edge);
        }
    }
    return pair<vector<Edge>, int>(MST, length);
}

void Kruskal::print(Graph airport, string filename) {
    pair<vector<Edge>, int> path = kruskal_mst(airport);
    ofstream file;
    file.open(filename);

    file << "The cost of the MST to traverse the graph is " + to_string(path.second) + " miles." << endl;
    file << "The edges are traversed in the following order:" << endl;

    for (auto data = path.first.end(); data != path.first.begin(); --data) {
        Edge edge = *data;
        file << edge.source + " to " + edge.dest + " is distance: " + to_string(edge.weight) << endl;
    }

    file.close();
}