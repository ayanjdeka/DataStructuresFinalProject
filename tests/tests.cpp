#include "../file.h"
#include "../airport.h"
#include "../graph.h"
#include "../bfs.h"
#include "../dijkstra.h"
#include "../kruskal.h"
#include "catch/catch.hpp"

#define good_minimal_airport "tests/test_data/good_minimal_airport.dat"
#define good_minimal_routes "tests/test_data/good_minimal_routes.dat"
#define bad_minimal_airport "tests/test_data/bad_minimal_airport.dat"
#define bad_minimal_routes "tests/test_data/bad_minimal_routes.dat"

// File Tests

TEST_CASE("Check good airports are read from file correctly")
{
    //read in minimal file with 5 good airports
    map<string, Airport> airports = make_airports(good_minimal_airport);

    //check all 5 airports were added
    REQUIRE(airports.size() == 5);
    //check a couple airports to see they were correctly constructed
    REQUIRE(airports["1"].ID_ == "1");
    REQUIRE(airports["1"].name_ == "Goroka Airport");
    REQUIRE(airports["1"].lat_ == "-6.081689834590001");
    REQUIRE(airports["1"].lon_ == "145.391998291");

    REQUIRE(airports["2"].ID_ == "2");
    REQUIRE(airports["2"].name_ == "Madang Airport");
    REQUIRE(airports["2"].lat_ == "-5.20707988739");
    REQUIRE(airports["2"].lon_ == "145.789001465");
}

TEST_CASE("Check airports with bad latitude and longitude aren't added")
{
    //this file has 3 good airports and 2 bad airports
    map<string, Airport> airports = make_airports(bad_minimal_airport);
    REQUIRE(airports.size() == 3);
}

TEST_CASE("Check good routes are read from file and added correctly")
{
    //this file should have 14 good routes total between 5 airports
    map<string, vector<string>> routes = make_routes(good_minimal_routes);
    vector<string> v1{"3", "4", "5"};
    vector<string> v2{"3", "5"};
    vector<string> v3{"1", "2", "5"};
    vector<string> v4{"2", "5"};
    vector<string> v5{"1", "2", "3", "4"};

    REQUIRE(routes.size() == 5);
    REQUIRE(routes["1"] == v1);
    REQUIRE(routes["2"] == v2);
    REQUIRE(routes["3"] == v3);
    REQUIRE(routes["4"] == v4);
    REQUIRE(routes["5"] == v5);
}

TEST_CASE("Check graph is made correctly from provided maps")
{
    map<string, Airport> airports = make_airports(good_minimal_airport);
    map<string, vector<string>> routes = make_routes(good_minimal_routes);
    Graph graph = make_graph(airports, routes);

    REQUIRE(graph.getVertices().size() == 5);
    REQUIRE(graph.getEdges().size() == 14);
    REQUIRE(graph.edgeExists("1", "3"));
    REQUIRE(graph.edgeExists("1", "4"));
    REQUIRE(graph.edgeExists("1", "5"));
    REQUIRE(graph.edgeExists("2", "3"));
    REQUIRE(graph.edgeExists("2", "5"));
    REQUIRE(graph.edgeExists("3", "1"));
    REQUIRE(graph.edgeExists("3", "2"));
    REQUIRE(graph.edgeExists("3", "5"));
    REQUIRE(graph.edgeExists("4", "2"));
    REQUIRE(graph.edgeExists("4", "5"));
    REQUIRE(graph.edgeExists("5", "1"));
    REQUIRE(graph.edgeExists("5", "2"));
    REQUIRE(graph.edgeExists("5", "3"));
    REQUIRE(graph.edgeExists("5", "4"));
}

TEST_CASE("Check bad routes aren't added to graph")
{
    //the routes file should have 1 good route and 10 bad ones
    map<string, Airport> airports = make_airports(good_minimal_airport);
    map<string, vector<string>> routes = make_routes(bad_minimal_routes);
    Graph graph = make_graph(airports, routes);

    REQUIRE(graph.getEdges().size() == 2);
    REQUIRE(graph.edgeExists("1", "2"));
    REQUIRE(graph.edgeExists("2", "3"));
}

// Airport Tests

TEST_CASE("Airport Constructor") {
    string id = "1";
    string name = "Tofino";
    string latitude = "49.079833";
    string longitude = "-125.775583";
    Airport airport = Airport(id, name, latitude, longitude);

    REQUIRE(airport.ID_ == id);
    REQUIRE(airport.name_ == name);
    REQUIRE(airport.lat_ == latitude);
    REQUIRE(airport.lon_ == longitude);
}

TEST_CASE("Airport Distance") {
    Airport first = Airport("1", "Goroka Airport", "-6.081689834590001", "145.391998291");
    Airport second = Airport("2", "Madang Airport", "-5.20707988739", "145.789001465");
    REQUIRE(abs(first.distance(second) - 66) < 5);
}

// BFS Tests

TEST_CASE("Check BFS")
{
    /*
        (0)            
    128 /   \ 290 
     /          \
   (1)          (2)
    The graph is this shape.
    */

    //Creates a specified graph to check if bfs traversal is correct or not
    Graph graph = Graph (true);
    graph.insertVertex("128");
    graph.insertVertex("290");
    graph.insertVertex("1");
    graph.insertVertex("2");

    graph.insertEdge("128", "0");
    graph.insertEdge("290", "0");
    graph.insertEdge("1", "128");
    graph.insertEdge("2", "290");

    bfs BFS;
    list<Vertex> trav = BFS.traversal(graph, "0");
    
    //Few test cases to check BFS accuracy
    REQUIRE(trav.size() == 5);
    REQUIRE(trav.front() == "0");
    trav.pop_front();
    REQUIRE(trav.front() == "290");
    trav.pop_front();
    REQUIRE(trav.front() == "128");
}

TEST_CASE("Check dijkstra")
{
    //Create a specific graph so we could know the algorithm actually works

    /*
       (2)
    5 /   \ 4 
     /     \
   (1)--9--(3)
    |      /|
    |    /  |
    7   2   2
    |  /    |
    |/      |
   (0)--0--(4)
     the graph is like this shape   
*/

    //test if it works for undirected graph

    Graph g = Graph(true);
    g.insertVertex("0");
    g.insertVertex("1");
    g.insertVertex("2");
    g.insertVertex("3");
    g.insertVertex("4");

    g.insertEdge("2", "1");
    g.insertEdge("2", "3");
    g.insertEdge("1", "3");
    g.insertEdge("1", "0");
    g.insertEdge("0", "4");
    g.insertEdge("4", "3");
    g.insertEdge("0", "3");

    g.setEdgeWeight("2", "1", 5);
    g.setEdgeWeight("2", "3", 9);
    g.setEdgeWeight("1", "3", 8);
    g.setEdgeWeight("1", "0", 7);
    g.setEdgeWeight("0", "4", 5);
    g.setEdgeWeight("4", "3", 2);
    g.setEdgeWeight("0", "3", 12);

    dijkstra d1 = dijkstra(g, "0", "1");
    dijkstra d2 = dijkstra(g, "0", "2");
    dijkstra d3 = dijkstra(g, "0", "8");
    dijkstra d4 = dijkstra(g, "4", "4");

    REQUIRE(d1.actual_distance == 7);
    REQUIRE(d2.actual_distance == 12);
    REQUIRE(d3.actual_distance == -1);
    REQUIRE(d4.actual_distance == 0);

}

TEST_CASE("Check Kruskal's Algorithm")
{
    //Create a specific graph so we could know the algorithm actually works

    /*
       (2)
    5 /   \ 4 
     /     \
   (1)--9--(3)
    |      /|
    |    /  |
    7   2   2
    |  /    |
    |/      |
   (0)--0--(4)
     the graph is like this shape   
*/

    //test if it works for undirected graph

    Graph sample = Graph(true);
    sample.insertVertex("0");
    sample.insertVertex("1");
    sample.insertVertex("2");
    sample.insertVertex("3");
    sample.insertVertex("4");

    sample.insertEdge("2", "1");
    sample.insertEdge("2", "3");
    sample.insertEdge("1", "3");
    sample.insertEdge("1", "0");
    sample.insertEdge("0", "4");
    sample.insertEdge("4", "3");
    sample.insertEdge("0", "3");

    sample.setEdgeWeight("2", "1", 5);
    sample.setEdgeWeight("2", "3", 2);
    sample.setEdgeWeight("1", "3", 9);
    sample.setEdgeWeight("1", "0", 7);
    sample.setEdgeWeight("0", "4", 0);
    sample.setEdgeWeight("4", "3", 2);
    sample.setEdgeWeight("0", "3", 2);

    Kruskal kruskal;
    pair<vector<Edge>, int> p = kruskal.kruskal_mst(sample);
    Edge edge;
    REQUIRE(p.second == 14);
}

