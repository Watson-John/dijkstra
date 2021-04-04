#ifndef PATH
#define PATH

//#include "node.h"
#include <iostream>

using namespace std;



class Path{

    static const int SIZE = 8;

    static const int INFINITY = 1000;

    int graph[SIZE][SIZE];

    int visited[SIZE];
    int unvisted[SIZE];
    int distance[SIZE];

public:

    // Paramaterized constructor

    void setgraph(int a [SIZE][SIZE]);



    void shortestPath();



















};
#endif

