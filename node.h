#ifndef NODE
#define NODE

class Node{

// Vertex name, A,B,C,D
char name;

// Shortest distance from start
int distance_from_start;

// The last vertex to get to this one
char last_vertex;

public:

    //Getters
    char getName();
    int getDistance();
    char getLastVertex();

    //Setters
    void setName(char);
    void setDistance(int);
    void setLastVertex(char);





};
#endif