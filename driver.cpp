// John Watson
// CS 365
// Project 1
// 4/11/2021


#include <iostream>
#include "path.h"

using namespace std;

int main(){

Path g;

int graph[8][8] =  { {0,4,3,0,0,0,0,0},
                     {4,0,2,5,0,0,0,0},
                     {3,2,0,3,6,0,0,0},
                     {0,5,3,0,1,5,0,0},
                     {0,0,6,1,0,0,5,0},
                     {0,0,0,5,0,0,2,7},
                     {0,0,0,0,5,2,0,4},
                     {0,0,0,0,0,7,4,0} };

g.setgraph(graph);

g.shortestPath();






}
