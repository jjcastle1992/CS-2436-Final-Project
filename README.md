# James Castle's Final Project COSC 2436 (Katrompas)

Date of last update: May 14, 2021

Purpose:
This program is a simple toy graph implemented in the form
of an airport flight route map.

Given a set of airports and routes, this ADT will create a graph that it can display
as a whole, traverse via Depth-First Search (DFS), or traverse via Breadth-First Search (BFS).

Future iterations may be able to:
  1. take in data from a .csv file or
  2. be able to plot the shortest route path from an origin airport to a final destination airport.
    Note: this ADT holds weights, but because shortest path/ minimum spanning trees aren't implemented, the weights are not
    utilized at this time. 
   
How to Use:
1. Create a Graph object to act as your container.
2. Use the addAirport and addRoute methods to build your network of airports and routes.
3. To traverse the graph use the:
   * displayGraph method to show the entire network of airports and routes in adjacency list form.
   * displayAirportInfo method to display info about a specific airport (using the internal ID).
   * depthFirstSearch method to traverse through the current network of airports using a DFS algorithm
   * breadthFirstSearch method to traverse through the current network of airports using a BFS algorithm
4. At any time you may call the following informational methods to provide additional info about your airport graph:
   * numberAirports method returns the number of airports currently in your graph as an int (you must COUT to display).
   * numberRoutes method returns the number of unique routes on the graph (undirected routes are only counted once)
   * findAirport method allows you pass in an internal airport ID and it returns the airport code if found (must COUT to display)
   * graphEmpty method tests to see if your graph is empty and returns true if it is. 
5. Use the removeRoute and removeAirport methods to remove any routes you'd like to take away or whole airports all together.
6. If you'd like to empty your graph, call the clearAirports method which will remove ALL airports and routes from the graph. 


The main components of this graph are
  * Airport: a vertex in the graph that contains:
    * an airport ID (added sequentially as airports are added beginning at 0).
    * an airport 3-letter code (i.e. AUS = Austin Airport) 
    * details for any routes connecting one airport to another (add/removeRoute methods can detect directed vs undirected edges):
        * departure airport 
        * arrival airport
        * route distance (in miles)
    
  * availableAirports: this is a vector that houses all of your airports. 
  * memory: this is a vector used to track airports visited in the DFS/BFS methods. 
  * dfsPosition: this is a vector used to track the current position during the traversal of a graph in DFS. 
  * bfsPosition: this is a double-ended queue used to track the current position during the traversal of a graph in BFS.
  * airportCount: count of all airportNodes in the graph.
  * routeCount: count of all unique edges in the graph (undirected edges only get counted the first time)
   
