CS 225 Final Report
Kavin Krishnasami, Param Mehta, Dharmil Jadav, Ayan Deka


The goal of our Final Project was to find all the possible paths between two airports as long as the total number of flights in the path is less than or equal to two. To do this, we used data from the OpenFlights dataset to build a graph that models all airports and routes provided by the dataset. To traverse this graph, we created a Breadth-First Search algorithm, which we used in our Dijkstra’s and Kruskal’s algorithms for the shortest path and the minimum spanning tree respectively.

First, we had to build the graph by reading the data from the airports and routes datasets. We built a map of all airports with the key being the airport ID and the value being an airport data structure generated for that airport. If the file is missing any important data on an airport, such as its latitude or longitude, the airport is not added. Next, we read the routes from the file. Routes are only added if both the source and destination nodes exist in the airports map. 
Finally, both the airports and routes maps are iterated over and added to a graph. The graph is weighted and directed, with the weights being the distance, calculated using the Haversine formula, from the source vertex airport to the destination vertex airport. 

The first algorithm we implemented for this project was a BFS traversal algorithm. First, we had to create a visited map so we could mark each node of the graph as visited as we performed the traversal. Then, we created a queue to push elements into to output them in the correct according to BFS. We then loop through the adjacency list and add nodes to the queue and mark them as visited on the map so we traverse through the entire graph.		

The second algorithm we implemented is Dijkstra’s algorithm is to find the shortest path between two airports. The reason for implementing this algorithm is that even if each airport is not connected, we can figure out the final shortest path to get to that airport using Dijkstra’s algorithm. Our project goal was to find the possible paths between two airports as long as the shortest distance can be covered in two flights. 

In the process of creating this algorithm, we figured out there are airports that the source airport is not able to reach so we made a function to get the number of airports the source airport actually reaches. Finally, we made a function that prints the shortest path from the source to the destination. 
The final algorithm we implemented is Kruskal’s algorithm for the Minimum Spanning Tree. We implemented this algorithm to find the shortest time to pass through all of the inputted airports excluding returns to the airport. This outputs the path that results in the shortest path to cycle through all the airports. We were able to use a priority queue for this algorithm and run it in O(Vlog(V)) time.

Overall, we feel as if we were able to successfully complete our goals for this project. The graph algorithms allow us to navigate through the large amounts of OpenFlights data to pinpoint certain paths and flights that we would want to take based on how convenient it would be to visit a certain location. In the future, we hope to expand upon this project to add additional features that will help people decide which flights to take and places to visit.
