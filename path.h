// John Watson
// CS 365
// Project 1
// 4/11/2021

#ifndef PATH
#define PATH

#include <iostream>

using namespace std;



class Path{

    static const int SIZE = 8;

    static const int INFINITY = 1000;

    // Raw user input of the Tree in array form
    int graph[SIZE][SIZE];

    // Nodes we have visited
    // initialized with value -1
    int visited[SIZE];
    //Nodes we havent visited
    int unvisited[SIZE];

    //Distance from Node A eg. index 2 = B's distance from A
    int distance[SIZE];

    // Previous Vertex. useful for createing path
    int prev_vertex[SIZE];

    // The current number of edges attached to each node
    int current_egdes[SIZE];

public:

    // Path Class Functions
    //*****************************

    Path();
    void setgraph(int a [SIZE][SIZE]);

    //*****************************



    // Helper Functions
    //*****************************

    int nextShortest(int);
    void calcDistance(int);
    void findEdges(int);
    int removeDuplicates(int arr[SIZE]);

    //*****************************


    // Main Algorithim
    //*****************************

    void shortestPath();

    //*****************************

};
#endif
