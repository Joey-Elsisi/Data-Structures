//Joseph ELsisi jre3wjh
//Lab 108
//Dec 1
//traveling.cpp
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <algorithm>

using namespace std;
/** 
 * Program traveling.cpp simulates the traveling sailsman problem using middle earth.
 *   
 */

#include "middleearth.h"
/** @brief computes distance
 *  
 *  @return float, the distance between two cities
 *  @param &me MiddleEarth object 
 *  @param start a string representing the first location
 *  @param dests a vector containing all the locations to travel to 
 */
float computeDistance (MiddleEarth &me, string start, vector<string> dests);
/** @brief prints the route
 * 
 *  @param start a string representing the first location 
 *  @param dests a vector containing all the locations to travel to 
 */
void printRoute (string start, vector<string> dests);
/** @brief the main function
 * 
 *  @return 0 upon sucess, exit(1) otherwise
 *  @param argc stores the number of command line arguments
 *  @param argv an array of command line arguments 
 */
int main (int argc, char **argv) {
    // check the number of parameters
    if ( argc != 6 ) {
        cout << "Usage: " << argv[0] << " <world_height> <world_width> "
             << "<num_cities> <random_seed> <cities_to_visit>" << endl;
        exit(0);
    }
    // we'll assume the parameters are all well-formed
    int width, height, num_cities, rand_seed, cities_to_visit;
    sscanf (argv[1], "%d", &width);
    sscanf (argv[2], "%d", &height);
    sscanf (argv[3], "%d", &num_cities);
    sscanf (argv[4], "%d", &rand_seed);
    sscanf (argv[5], "%d", &cities_to_visit);
    // Create the world, and select your itinerary
    MiddleEarth me(width, height, num_cities, rand_seed);
    //for(int i = 1; i <= cities_to_visit; i++){
        //cout << i << ". ";
        vector<string> dests = me.getItinerary(cities_to_visit);
        string start = dests[0];
        sort(dests.begin()+1, dests.end());
        //create a temporary vector that holds the vector without the start value, this will be permuatated/printed
        dests =  vector<string>(dests.begin()+1, dests.end());
        float smallest_dist = computeDistance(me, start, dests);
        vector<string> smallest_path = dests;
        while(next_permutation(dests.begin(), dests.end())){
            float temp_dist = computeDistance(me, start, dests);
            if(temp_dist < smallest_dist) {
                smallest_dist = temp_dist;
                smallest_path = dests;
            }
        }
        cout << "Minimum path has distance " << smallest_dist << ": ";
        printRoute(start, smallest_path);
        cout << endl;
    //}
    return 0;
}

// This method will compute the full distance of the cycle that starts
// at the 'start' parameter, goes to each of the cities in the dests
// vector IN ORDER, and ends back at the 'start' parameter.
float computeDistance (MiddleEarth &me, string start, vector<string> dests) {
    float distance = 0;
    distance += me.getDistance(start, dests[0]);
    for(int i = 0; i < dests.size() - 1; i++){
        distance += me.getDistance(dests[i], dests[i+1]);
    }
    distance += me.getDistance(dests.back(), start);
    return distance;
}

// This method will print the entire route, starting and ending at the
// 'start' parameter.  The output should be of the form:
// Erebor -> Khazad-dum -> Michel Delving -> Bree -> Cirith Ungol -> Erebor
void printRoute (string start, vector<string> dests) {
    cout << start << " -> ";
    for(int i = 0; i < dests.size(); i++){
        cout << dests[i] << " -> ";
    }
    cout << start << endl;
}
