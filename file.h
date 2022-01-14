#pragma once

#include "airport.h"
#include "graph.h"

#include <map>
#include <vector>
#include <fstream>
#include <iostream>

using namespace std;

//given data file of airports, read into airport structure
//return map of airport id as string to airport name
map<string, Airport> make_airports(string file_name);

//given data file of routes, read into dictionary
//return map of airport id to vector of all destinations
map<string, vector<string>> make_routes(string file_name);

//given map of airport id to airport structure and map of airport id to destination airport IDs
//return a weighted, directed graph of all airports and their connecting routes
Graph make_graph(map<string, Airport> airports, map<string, vector<string>> routes);