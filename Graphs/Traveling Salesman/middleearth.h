#include <iostream>
#include <vector>
#include <string>
#include <map>

#ifndef MIDDLEEARTH_H
#define MIDDLEEARTH_H

using namespace std;

// see the comments in the lab11 write-up, or in middleearth.cpp
/** 
 * Class MiddleEarth stores data and functionality for all locations in lord of the rings  
 *   
 */
class MiddleEarth {
private:
    int num_city_names, xsize, ysize;
    vector<float> xpos, ypos;
    vector<string> cities;
    float *distances;
    map<string, int> indices;

public:
    /** @brief middleearth Constructor
 * Iluvatar, the creator of Middle-Earth
 * @param xsize the horizontal width of middle earth
 * @param ysize the vertical height of middle earth
 * @param num_cities the number of cities in middle earth
 * @param seed sets up the random number seed
 * 
 */
    MiddleEarth (int xsize, int ysize, int numcities, int seed);
    /** @brief A destructor of middle earth
  * 
  *Sauron, the destructor of Middle-Earth.
  */
    ~MiddleEarth();
    /** @brief outputs the middle earth map.
  * 
  *The Mouth of Sauron!  (prints out info on the created 'world')
  */
    void print();
    /** @brief putputs a tab-separated table of the distances
 * 
 * 
 * // (this can be loaded
 * into Excel or similar)
 */
    void printTable();
    /** @brief getDistance returns the distance between two cities
 * 
 * This method returns the distance between the two passed cities.  If
 * we assume that the hash table (i.e. the map) is O(1), then this
 * method call is also O(1)
 * @return float, the distance between 2 cities
 * @param city1 a city
 * @param city2 another city
 * 
 */
    float getDistance (string city1, string city2);
    /** @brief gets an Itinerary
 * 
 * Returns the list of cities to travel to.  The first city is the
 * original start point as well as the end point.  The number of
 * cities passed in does not include this start/end point (so there
 * will be length+1 entries in the returned vector).
 * @return vector, the cities to travel to
 * @param length the number of cities to travel
 * 
 */
    vector<string> getItinerary(unsigned int length);
};

#endif
