#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int checkRight(vector<vector<int>> grid, int i, int j){
    if (i + 3 >= grid.size()){
        return -1;
    }
    else {
        return grid[i][j] * grid[i+1][j] * grid[i+2][j] * grid[i+3][j];
    }  
}
int checkDown(vector<vector<int>> grid, int i, int j){
    if (j + 3 >= grid.size()){
        return -1;
    }
    else {
        return grid[i][j] * grid[i][j+1] * grid[i][j+2] * grid[i][j+3];
    }  
}
int checkLeftDiagonal(vector<vector<int>> grid, int i, int j){
    if (j + 3 >= grid.size() || i - 3 < 0){
        return -1;
    }
    else {
        return grid[i][j] * grid[i-1][j+1] * grid[i-2][j+2] * grid[i-3][j+3];
    }  
}
int checkRightDiagonal(vector<vector<int>> grid, int i, int j){
    if (j + 3 >= grid.size() || i + 3 >= grid.size()){
        return -1;
    }
    else {
        return grid[i][j] * grid[i+1][j+1] * grid[i+2][j+2] * grid[i+3][j+3];
    }  
}

//checks each point and find right, down, rigth down and left down
int gridTraversal(vector<vector<int>> grid){
    
    int maxMultiple = -1;
    int temp;
    
    for (int i = 0; i < 20; i++) {
        for (int j = 0; j < 20; j++) {
            temp = checkRight(grid, i ,j);
            if ( temp > maxMultiple)
                maxMultiple = temp;
            temp = checkDown(grid, i, j);
            if ( temp > maxMultiple)
                maxMultiple = temp;
            temp = checkLeftDiagonal(grid, i, j);
            if ( temp > maxMultiple)
                maxMultiple = temp;
            temp = checkRightDiagonal(grid, i, j);
            if ( temp > maxMultiple)
                maxMultiple = temp;
        }
    }
    
    return maxMultiple;
}


int main() {
    
    int gridSize = 20;
    
    vector<vector<int>> grid( gridSize , vector<int> (gridSize, 0));
    
    for (int i = 0; i < 20; i++) {
        for (int j = 0; j < 20; j++) {
            cin >> grid[i][j];
        }
    }
    
    //test print
    // for (int i = 0; i < 20; i++) {
    //     for (int j = 0; j < 20; j++) {
    //         cout << grid[i][j] << " ";
    //     }
    //     cout << endl;
    // }
    
    cout << gridTraversal(grid) << endl;
    
    return 0;
}
