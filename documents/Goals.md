CS 225 Data Structures Final Project Proposal (djadav2-ayand2-kavinsk2-paramum2)

**Leading Question**

The goal of our final project is to find all the possible paths of flights between two airports as
long as the total number of flights in the path is less than or equal to two. We want to answer
this question because it would be useful to see all the possible paths between two destinations
that will take a reasonable amount of time and money(which is why we restrict it to two flights
maximum). A successful project would allow us to input two airport destinations and receive an
output that gives us all the “reasonable” paths between the two airports.

**Dataset Acquisition and Processing:**

We will collect that data from the OpenFlights dataset (<https://openflights.org/data.html>). From
here, we will take a look at the data and see if there are any NaN’s or missing data to clean up.
After ensuring the dataset is up to standards (either by manually filling out missing data or
dropping NaNs) then we will load/read the data. We would load all the airports as nodes with a
distance being the variable factor (distance between two nodes/airports). From here we will
implement our algorithms and traversals explained below.

**Graph Algorithms and Traversal:**

In order to answer our primary question regarding the possible flights between two airports
with or without a connecting flight, we will be implementing the Breadth-First algorithm for
traversing through all the connecting flights and their paths between two airports. This would
begin by taking in two cities and implementing a map to sort each connecting city and their
total distance. The runtime for this traversal would be O(n) as we would only need to traverse
through each of the connecting airports of the starting airport.

We would then implement the Djikstra’s algorithm to find the shortest path between these two
cities through a connecting city using the variable factor we discussed earlier. The output of this
would be a single path from the starting city to the destination with a connecting flight in the
middle. For example, if we input San Francisco International Airport (SFO) to John F. Kennedy
International Airport (JFK) with a variable factor of 0.5, we would most likely find the shortest
distance to be through Denver Airport (DEN). Implementing the Djikstra’s algorithm would have
a runtime of O(E log(V)) where E represents the number of edges and V represents the number
of vertices.

The second algorithm to be implemented in our project is the Minimum Spanning Tree of a
Graph algorithm, specifically Kruskal's algorithm, in order to find the shortest distance 
to pass through all of the inputted airports excluding returns to the airports. This 
would output the path that results in the shortest path to cycle through all the airports.
Runtime for this algorithm is O(ElogE) or O(ElogV). Sorting of edges takes O(ELogE) time. 
After sorting, we iterate through all edges and apply the find-union algorithm. The find
and union operations can take at most O(LogV) time. So overall complexity is O(ELogE + ELogV) time.

**Timeline:**

Before the first check in of the project, we plan to finish at least half of the total project and
most of the coding aspect. The reason for us trying to finish most of the coding aspect about
this project is because we want to allocate time during the end to finish the final report of the
project and to also finish our last part of the project video. Before the check in, we plan to finish
the data acquisition part of it, processing the actual data, and implementing our first graph
algorithm.

Data acquisition: November 15th
Data processing: November 22nd
Completion of BFS Traversal: November 29th
Mid-Project Checkin (Nov 29th - Dec 1st)
Completion of Djikstra's: December 3rd
Completion of Minimum Spanning Tree: December 5th
Completion Of Video and Final Report: December 10th
Finish Project: December 13th
