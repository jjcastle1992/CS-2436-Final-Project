# James Castle's Final Project COSC 2436 (Katrompas)
This program is a simple toy graph implemented in the form
of an airport flight route map.

The main components of this graph are
  * Airport: a vertex in the graph that contains:
    * an airport ID (added sequentially as airports are added beginning at 0).
    * an airport 3-letter code (i.e. AUS = Austin Airport) 
    * details for any routes connecting one airport to another:
        * departure airport (each route is roundtrip, so the "departure/arrival" status is arbitrary)
        * arrival airport
        * route distance (in miles)
