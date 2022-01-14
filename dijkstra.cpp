#include "dijkstra.h"

using namespace std;
typedef pair<double, Vertex> dis_node;
#define INF numeric_limits<double>::max()

typedef string Vertex;

dijkstra::dijkstra(Graph g, Vertex start, Vertex end) : g_(true, true)
{
	g_ = g;
	start_ = start;
	end_ = end;
	state = "";

	if (g_.adjacency_list[start].size() == 0 || g_.adjacency_list[end].size() == 0) {
		actual_distance = -1;
		state = "invalid";
	}

	for (auto &v : g_.getVertices())
	{
		distance[v] = +INF;
	}

	if (end == start) {
		actual_distance = 0;
		state = "same";
	}

	distance[start] = 0;

	priority_queue<dis_node, vector<dis_node>, greater<dis_node>> Q; 

	Q.push(make_pair(0, start));

	while (!Q.empty())
	{
		Vertex u = Q.top().second; 					   
		Q.pop();

		for (auto it = g_.adjacency_list[u].begin(); it != g_.adjacency_list[u].end(); it++)
		{
			Vertex v = (*it).first;
			int weight = g_.getEdgeWeight(u, v);
			if (distance[v] > distance[u] + weight)
			{
				distance[v] = distance[u] + weight;
				visited.push_back(u);
				Q.push(make_pair(distance[v], v));
				path[v] = u;
			}
		}
	}

	if (state == "same") {
		actual_distance = 0;
	} else if (state == "invalid") {
		actual_distance = -1;
	} else {
		actual_distance = distance[end];
	}
	
}

void dijkstra::print(Graph graph, Vertex originalAirport, Vertex endAirport, string fileName) {
    dijkstra d(graph,originalAirport, endAirport);
	ofstream file;
    file.open(fileName);
	if (d.state == "invalid") {
		file << "There are no nodes that connect to one of the nodes you entered" << endl;
	} else if (d.state == "same") {
		d.actual_distance = -2;
		file << "The starting and ending nodes are the same" << endl;
	} 
	file << "The distance between both the nodes is " << d.actual_distance << endl;
	file.close();
}
