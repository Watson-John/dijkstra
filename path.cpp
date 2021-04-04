#include "path.h"

void Path::setgraph(int a[SIZE][SIZE]){

for (int x=0 ; x < SIZE; x++){
  for (int y=0 ; y < SIZE; y++){
    graph[x][y] = a[x][y];
  }
}


 for (int i = 0; i < SIZE; ++i){
        for (int j = 0; j < SIZE; ++j){
            cout << a[i][j] << ' ';
        }
        cout << endl;
    }


for(int i =0; i< SIZE; i++){
    distance[i] = INFINITY;
}


}



void Path:: shortestPath(){

}