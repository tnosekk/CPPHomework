#include <iostream>
#include <random>
#include <unistd.h>
#include <stdlib.h>

const int N = 30; // matrix size

void rand_bool(int W[N][N],double probability){
    // random matrix values generator
    srand(time(NULL));
    double r;
    double limit = {probability * RAND_MAX + probability};
    for(int i=0;i<N;i++){
        for(int j=0;j<N;j++){
            r = rand() < limit;
            W[i][j] = r;
        }
    }
}
int live_cell_count(int W[N][N],int i,int j){
    // function to count live cells around given cell
    int live_cells = 0;
    for(int k = i-1; k <= i+1; k++){
        for(int l = j-1; l <= j+1; l++){
            if ((k == i && l == j) 
                || (k < 0 || l < 0)
                || (i >= N || j >= N)) {
                continue;
                }
            if(W[k][l] == 1) live_cells++;
        }
    }
    return live_cells;
}


void life(int W[N][N]){
    // main game function
    int dead_cell = 0;
    int live_cell = 1;

    for(int i = 0; i < N; i++){
        for(int j = 0; j< N; j++){
            int live_cells = live_cell_count(W, i, j);
            if(W[i][j] == dead_cell && live_cells == 3) W[i][j] = 1;
            if(W[i][j] == live_cell && (live_cells != 2 && live_cells != 3)) W[i][j] = 0;
        }
    }
}

int main(){

    int W[N][N];
    
    rand_bool(W, 0.3);
    int iterations = 10000;
    for(int i = iterations; i != 0; i--){
        usleep(50000);
        system("clear");
        for(int i=0;i<N;i++){
            for(int j=0;j<N;j++){
                std::cout<<W[i][j]<<" ";
            }
            std::cout<<std::endl;
        }
        life(W);
    }

}

