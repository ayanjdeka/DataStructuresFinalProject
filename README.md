# djadav2-paramum2-kavinsk2-ayand2

Final Project Repository for CS 225 - Fall 2021

#### Contributers

* Dharmil Jadav djadav2
* Kavin Krishnasami kavinsk2
* Ayan Deka ayand2 
* Param Mehta paramum2

#### Important links

* [Presentation Slides](https://docs.google.com/presentation/d/1WuMfw25BOzZiuLUEP_XebO2xZklLKVBC0kmHiw7ufZU/edit?usp=sharing)
* [Presentation Video](https://youtu.be/pty30jzhG3I)

### About The Project
This project utilizes the OpenFlights public routes and airports dataset to build a graph data structure containing all airports and routes. 
This allows us to find the shortest path between any airports using Dijsktra's Algorithm, as well as the creation of Minimum Spanning Tree with Kruskal's algorithm that it used to find the minimum cost of linking all airports together.

### Data Requirements
Both files are comma delimited, with linebreaks being "\n". Fields cannot contain either of these characters.

##### airports.dat

Airport | Name | City | Country | IATA | ICAO | Latitude | Longitude | Altitude | Timezone | DST | Tz database time zone | Type | Source 
--------|--------|--------|--------|--------|--------|--------|--------|--------|--------|--------|--------|--------|--------|
Int | String | String | String | String | String | Float | Float | Int | Int | String | String | String | String | 

##### routes.dat

Airline | Airline ID | Source Airport | Source Aiport ID | Destination Airport | Destination Airport ID | Codeshare | Stops | Equipment
--------|--------|--------|--------|--------|--------|--------|--------|--------|
Int | Int | String | Int | String | Int | String | Int | String |

### Structure
Output files, including the Dijsktra shortest distance output, Kruskal's Minimum Spanning Tree order of creation, and the BFS traversal order are located in the output folder.

Data is located in the data folder.

The graph is created from file by functions contained in file.cpp, including make_airports, make_routes, and make_graph.

All testing files are in the testing folder.

### Running the project

The executable can be made with 'make' in the root of the project.

This will generate an executable named 'final_project'

The test executable can be made with 'make test' in the root of the project

This will generate an executable named 'test'
