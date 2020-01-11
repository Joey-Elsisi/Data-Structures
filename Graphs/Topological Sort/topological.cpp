//Joseph ELsisi jre3wjh
//Lab 108
//Dec 1
//topological.cpp

#include <iostream>
#include <fstream>
#include <stdlib.h>
#include <vector>
#include <unordered_map>
#include <queue>
#include <deque>
using namespace std;
/**
 * node is an implementation of a graph's vertex
 */
struct node {
    string name; /*!< the string representation of the course */
    int id; /*!< a unique identifier to index the array of nodes */
    int indegree; /*!< the number of recieving edges */
    node * next; /*!< the next adjacent node */
};

/** @brief performs the topological sort
 *
 *  @return return_val, the string representation of the sorted graph 
 *  @param adj_list a list that stores vertices and their adjacent pairs
 *  @param container a hashtable that stores vertices with respect to their string representation
 *  @see node
 */
string topsort(vector <node*> adj_list, unordered_map<string, node*> container);

/** @brief the main function
 * 
 *  @return 0 upon sucess, exit(1) otherwise
 *  @param argc stores the number of command line arguments
 *  @param argv an array of command line arguments 
 */
// we want to use parameters
int main (int argc, char **argv) {
    // verify the correct number of parameters
    if ( argc != 2 ) {
        cout << "Must supply the input file name as the one and only parameter" << endl;
        exit(1);
    }
    // attempt to open the supplied file
    ifstream file(argv[1], ifstream::binary);
    // report any problems opening the file and then exit
    if ( !file.is_open() ) {
        cout << "Unable to open file '" << argv[1] << "'." << endl;
        exit(2);
    }
    // read in two strings
    string s1, s2;
    file >> s1;
    file >> s2;
    int counter = -1;
    unordered_map<string, node*> container;
    vector <node*> adj_list;
    while(s1[0] != '0'){
        if(container.find(s1) == container.end()){
            counter++;
            node * temp = new node{s1, counter, 0, NULL};
            container[s1] = temp;
            adj_list.push_back(temp);
        }
        if(container.find(s2) == container.end()){
            counter++;
            node * temp = new node{s2, counter, 0, NULL};
            container[s2] = temp;
            adj_list.push_back(temp);
        }
        //node * curr_node = adj_list[container[s1]];
        node * curr_node = container[s1];
        while(curr_node -> next != NULL){
            curr_node = curr_node -> next;
        }
        curr_node -> next = new node{s2, container[s2] -> id, 0, NULL};
        file >> s1;
        file >> s2;
    }

    //debugging
    // for(unsigned int i = 0; i < adj_list.size(); i++){
    //     node * curnode = adj_list[i];
    //     cout << curnode -> name << endl;
    //     while(curnode -> next != NULL){
    //         curnode = curnode -> next;
    //         cout << "--- " << curnode -> name << endl;
    //     }
    // }

    string str = topsort(adj_list, container);
    cout << str << endl;


    // close the file before exiting
    file.close();
    return 0;
}

string topsort(vector <node*> adj_list, unordered_map<string, node*> container){
    string return_val = "";
    queue <node*> q;
    int num_vertices = adj_list.size();
    int counter = 0;
    for(int i = 0; i < num_vertices; i++){
        node * curnode = adj_list[i];
        while(curnode -> next != NULL){
            container[curnode -> next -> name] -> indegree++;
            curnode = curnode -> next;
        }
    }
    //files the queue with all nodes to be deleted.
    //for each vertex v
    unordered_map<string, node*>::iterator itr = container.begin();
    while(itr != container.end()){
        if(itr -> second -> indegree == 0){
            q.push(itr -> second);
            //for debuging
            //cout << q.back() -> name << " the element with indegree 0" << endl;
        }
        itr++;
    }
    //while(!q.isEmpty())
    while(q.front() != NULL){
        counter++;
        node * v = q.front();
        q.pop();
        return_val += v -> name + " ";
        //now look into v -> id's spot in the adjacency list
        //this will show, after the first node!!!, all the nodes to deccrememnt..
        //for()
        node * temp = adj_list[v -> id];
        while(temp -> next != NULL){
            temp = temp -> next;
            node * curr_node = container[temp -> name];
            curr_node -> indegree -= 1;
            if(curr_node -> indegree == 0){
                q.push(temp);
            }
        }
    }
    if(counter != num_vertices){
        cout << "Cycle found" << endl;
        exit(1);
    }
    // //for debuging
    // itr = container.begin();
    // int count = 0;
    // while(itr != container.end()){
    //     cout << itr -> first << " has indegree " << itr -> second -> indegree << "and id " << itr -> second -> id << endl;
    //     itr++;
    //     //cout << "adj_list at " << itr -> second -> id << " " << adj_list[itr -> second -> id] -> name << endl;
    //     count++;
    // }
    return return_val;
}