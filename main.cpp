#include "kruskal.h"
#include "file.h"
#include "bfs.h"
#include "dijkstra.h"
#include <iostream>

using namespace std;

#define airport_file "data/airport.dat"
#define routes_file "data/routes.dat"
#define bfs_output "bfs_output.dat"
#define kruskal_output "kruskal_output.dat"

int main() {
    map<string, Airport> airports = make_airports(airport_file);
    map<string, vector<string>> routes = make_routes(routes_file);
    Graph airport_graph = make_graph(airports, routes);

    bfs BFS;
    BFS.print(airport_graph, "1", bfs_output);
    
    //djistrka
    dijkstra d(airport_graph, "5567", "2009");
    d.print(airport_graph, "5567", "2009", dijkstra_output);

    //kruskal
    Kruskal kruskal;
    kruskal.print(airport_graph, kruskal_output);

    return 0;
}