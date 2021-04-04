#include "node.h"


    char Node::getName(){
        return name;
    }
    int Node::getDistance(){
        return distance_from_start;
    }
    char Node::getLastVertex(){
        return last_vertex;
    }

    void Node::setName(char newName){
        name = newName;
    }
    void Node::setDistance(int newDistance){
        distance_from_start = newDistance;
    }
    void Node::setLastVertex(char newVertex){
        last_vertex = newVertex;
    }