#include "airport.h"
#include "bfs.h"

#include <iostream>
#include <vector>
#include <map>
#include <string>
#include <fstream>

typedef string Vertex;

using namespace std;


list<Vertex> bfs::traversal(Graph &graph, Vertex originalAirport)
{   
    vector<Vertex> numberOfVertices = graph.getVertices();
    map<Vertex, bool> visited;
    list<Vertex> queue;

    for (size_t i = 0; i < numberOfVertices.size(); i++)
    {
        visited[numberOfVertices[i]] = false;
    }

    visited[originalAirport] = true;
    queue.push_back(originalAirport);

 
    while (!queue.empty())
    {
        originalAirport = queue.front();      
        orderOfTraversal.push_back(originalAirport);
        queue.pop_front();
        for (auto it = graph.adjacency_list[originalAirport].begin(); it != graph.adjacency_list[originalAirport].end(); ++it)
        {
            if (visited[it->first] == false)
            {
                visited[it->first] = true;
                queue.push_back(it->first);
            }
        }
    }
    return orderOfTraversal;
}

void bfs::print(Graph &graph, Vertex originalAirport, string Filename){

    list<Vertex> traversalToPrint = traversal(graph,originalAirport);
    ofstream file;
    file.open(Filename);
    file << "This the traversal in BFS Order" << endl;

    for (auto data = traversalToPrint.begin(); data != traversalToPrint.end(); ++data){
        file << *data << ",";
    }
    file.close();
}