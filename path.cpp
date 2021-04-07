// John Watson
// CS 365
// Project 1
// 4/11/2021


#include "path.h"


// Path Class Functions
//*****************************

Path::Path(){

        int i;

        for(i = 0; i<SIZE; i++) {
                visited[i] = -1;
                current_egdes[i] = -1;
                unvisited[i] = i;

                if(i > 0) {
                        prev_vertex[i] = -1;
                        distance[i] = INFINITY;
                        unvisited[i] = i;
                }else if (i == 0) {
                        distance[i] = 0;
                        prev_vertex[i] = 0;
                        unvisited[i] = -1;
                }


        }
}

void Path::setgraph(int a[SIZE][SIZE]){

        for (int x=0; x < SIZE; x++) {
                for (int y=0; y < SIZE; y++) {
                        graph[x][y] = a[x][y];
                }
        }


// Prints 2D array to verify safe copy
// for (int i = 0; i < SIZE; ++i){
//        for (int j = 0; j < SIZE; ++j){
//            cout << graph[i][j] << ' ';
//        }
//        cout << endl;
//    }

}


//*****************************



// Helper Functions
//*****************************


// Looks at distance (distance from start) and find the node with the shortest path so far
int Path::nextShortest(int nodeIndex){



        calcDistance(nodeIndex);

        // cout<<endl<<"Distance"<<endl;
        // for(int i = 0; i < SIZE; i++) {
        //
        //         cout<<distance[i]<<", ";
        //
        // }
        // cout<<endl;


        // This will hold all valid  (not -1) indexes from the visited list
        int valid_index[SIZE];
        int p = 0;

        for(int i = 0; i < SIZE; i++) {

                if(unvisited[i] != -1) {
                        valid_index[p] = unvisited[i];
                        p++;
                }

        }
        // for(int i = 0; i <SIZE; i++) {
        //         cout<<" At index: "<<i<<" value: " <<valid_index[i]<<endl;
        // }


        //Using only valid indexes from above loop through distance;
        int i = 1;
        int index;
        int value;


        index = valid_index[0];
        int temp = distance[index];

        //cout<<endl<<"At index "<< index<< " the value: "<<temp<<endl;

        do {

                index = valid_index[i];
                value = distance[index];

                //cout<<"At index "<< index<< " the value: "<<value<<endl;



                if(temp > value) {
                        temp = value;
                }


                i++;

        } while(i < p);



        //cout<<endl<<"Smallest node's value is: "<< temp<<endl;



        int min_index = 1;


        for(int j = 0; j < SIZE; j++) {
                if(distance[j] == temp) {
                        min_index = j;
                }
        }


        //cout<<"Smallest node's index is: "<<min_index<<endl;


        // Add index to black list (unvisited)
        unvisited[min_index] = -1;




        return min_index;
}


// Calulates the Distance from the node to each of its attached nodes
void Path::calcDistance(int nodeIndex){

// represents the index of the next shortest node to travel to
        int nextShortest = -1;

        findEdges(nodeIndex);


        for (int i = 0; i <SIZE; i++) {

                if (current_egdes[i] != -1) {

                        // temp holds the index for the distance value in the graph
                        int temp = current_egdes[i];

                        //cout<<"temp: "<<temp<<endl;

                        int a = graph[nodeIndex][temp];

                        //cout<<"a: "<<a<<endl;

                        int b = distance[nodeIndex];

                        //cout<<"b: "<<b<<endl;

                        int c = a+b;

                        //cout<<"c: "<<c<<endl;



                        if (c < distance[temp]) {
                                distance[temp] = c;
                                prev_vertex[temp] = nodeIndex;

                        }
                }
        }
}


//Finds the index of the Edges And determines if the Node has been vistied
// Input is the x or y on the 2D array to scan for edges. (represents node see note)
void Path::findEdges(int nodeIndex){

// NOTE
// Index        0   1   2   3   4   5   6   7
// Node Letter  A   B   C   D   E   F   G   Z


        // Clear the array
        for (int g = 0; g<SIZE; g++) {
                current_egdes[g] = -1;
        }


        int p = 0;

        for(int i = 0; i < SIZE; i++) {


                // if # at index is non zero then its an Edge
                if (graph[i][nodeIndex] != 0) {

                        // Stores index in edge array
                        current_egdes[p] = i;

                        p++;
                }

        }




        // for(int i = 0; i <SIZE; i++){
        //   cout<< "At index "<<i<<" edge index = "<<current_egdes[i]<<endl;
        // }



        // Lets check if the nodes attached to the edges have already been visited
        for(int j = 0; j < SIZE; j++) {
                int current_visited = visited[j];

                for(int k = 0; k < SIZE; k++) {
                        //if we find the visited in our edge array replace it with the defalut -1
                        if(current_egdes[k] == current_visited) {
                                current_egdes[k] = -1;
                        }
                }





        }











}

int Path::removeDuplicates(int arr[SIZE]){


        int temp[SIZE];

        // Start traversing elements
        int j = 0;
        for (int i=0; i<SIZE-1; i++)


                if (arr[i] != arr[i+1])
                        temp[j++] = arr[i];


        temp[j++] = arr[SIZE-1];


        for (int i=0; i<j; i++)
                arr[i] = temp[i];

        return j;
}


//*****************************


// Main Algorithim
//*****************************
void Path:: shortestPath(){

        // NOTE
        // Index        0   1   2   3   4   5   6   7
        // Node Letter  A   B   C   D   E   F   G   Z


        int j = 0;

        for(int p = 0; p <SIZE; p++) {
                j = nextShortest(j);
        }





        int length = removeDuplicates(prev_vertex);


        cout<<" The shortest route is ";
                for(int i = 0; i<length; i++ ) {
                if(prev_vertex[i] == 0) {
                        cout<<"a, ";
                }else if(prev_vertex[i] == 1) {
                        cout<<"b, ";
                }else if(prev_vertex[i] == 2) {
                        cout<<"c, ";
                }else if(prev_vertex[i] == 3) {
                        cout<<"d, ";
                }else if(prev_vertex[i] == 4) {
                        cout<<"e, ";
                }else if(prev_vertex[i] == 5) {
                        cout<<"f, ";
                }else if(prev_vertex[i] == 6) {
                        cout<<"g, ";
                }else if(prev_vertex[i] == 7) {
                        cout<<"z, ";
                }




                }
                cout<<"z ";

                cout<<"with length "<< distance[SIZE-1]<<endl;




// Visit node A at index 0
// Look at its unvisited neighbors
// Calculate the distance
// if calculated < known distance replace value in table
// Write previous vertex to array
// Add node A at index 0 to visited

// Visit unvisited vertex with smallest known distance




}


//*****************************
