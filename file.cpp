#include "file.h"

#include <map>
#include <vector>
#include <fstream>
#include <iostream>

using namespace std;

//given data file of airports, read into airport structure
//return map of airport id as string to airport name
map<string, Airport> make_airports(string file_name)
{
	ifstream data_file;
	data_file.open(file_name);
	map<string, Airport> airports;

	while (data_file.good())
	{
		Airport curr_airport;
		string bad_info;

		getline(data_file, curr_airport.ID_, ',');
		getline(data_file, curr_airport.name_, ',');

		getline(data_file, bad_info, ',');
		getline(data_file, bad_info, ',');
		getline(data_file, bad_info, ',');
		getline(data_file, bad_info, ',');

		getline(data_file, curr_airport.lat_, ',');
		getline(data_file, curr_airport.lon_, ',');
		getline(data_file, bad_info, '\n');

		try
		{
			stof(curr_airport.lon_);
			stof(curr_airport.lat_);

			airports[curr_airport.ID_] = curr_airport;
		}
		catch (...)
		{
			//Bad data
		}
	}
	data_file.close();
	return airports;
}

//given data file of routes, read into dictionary
//return map of airport id to vector of all destinations
map<string, vector<string>> make_routes(string file_name)
{
	ifstream data_file;
	data_file.open(file_name);
	map<string, vector<string>> routes;

	while (data_file.good())
	{
		string bad_info;
		string vertex_ID;
		string destination_ID;

		getline(data_file, bad_info, ',');
		getline(data_file, bad_info, ',');
		getline(data_file, bad_info, ',');
		getline(data_file, vertex_ID, ',');

		getline(data_file, bad_info, ',');
		getline(data_file, destination_ID, ',');

		getline(data_file, bad_info, '\n');

		//check if vertex_ID already exists in dict
		//if so, add to vect
		if (routes.find(vertex_ID) == routes.end())
		{
			routes[vertex_ID] = vector<string>();
		}
        routes[vertex_ID].push_back(destination_ID);
	}
	data_file.close();

	return routes;
}

//given map of airport id to airport structure and map of airport id to destination airport IDs
//return a weighted, directed graph of all airports and their connecting routes
Graph make_graph(map<string, Airport> airports, map<string, vector<string>> routes)
{
	Graph graph = Graph(true, true);

	//add all vertices
	for (auto &airport: airports)
	{
		graph.insertVertex(airport.first);
	}

	//add routes
	for (auto &route: routes)
	{
		string start = route.first;
		//only add routes when we have a vertex for both start and destination
		if (graph.vertexExists(start) && airports.find(start) != airports.end())
		{
			Airport start_airport = airports[start];
			for (auto &destination: route.second)
			{
				if (airports.find(destination) != airports.end() && airports.find(start) != airports.find(destination))
				{ 
					// adding weight to each edge
					Airport destination_airport = airports[destination];
					graph.insertEdge(start, destination);
					graph.setEdgeWeight(start, destination, start_airport.distance(airports[destination]));
					graph.setEdgeLabel(start, destination, start_airport.name_ + "To" + destination_airport.name_);
				}
			}
		}
	}

	return graph;
}