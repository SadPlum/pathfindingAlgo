#include <string.h>
#include <stdbool.h>

int search(int array[10][10], int startx,int starty){

    printf("the strarting point, %d, axis' are\nx=%d & y=%d\n", array[starty][startx], startx, starty);
    int counter =0;
    int grids[]={}; 

    return 0;
};

// Checks if the x and y coordinates are within the 10x10 grid
bool outOfBounds(int x, int y) {
    if(x > 0 && x < 10) {
        if(y > 0 && y < 10) {
            return true;
        }
    }
    return false;
};

int firstArr(int grid[10][10], int startx,int starty) {
    int indexesx[2] = {startx+1, startx-1};
    int indexesy[2] = {starty+1, starty-1};
    int array[]={};
    int indexCounter =0;
    for( int i=0; i< 2; i++) {
        for(int j=0; j< 2; j++) {
        
            int x = indexesx[i];
            int y = indexesy[j];
            if(outOfBounds(x,y) == true){
                printf("this is x %d, this is y %d\n",x,y);
                if(grid[x][y]== 0) {
                    printf("this is grid %d\n",grid[x][y]);
                    int arr[2] = {i,j};
                    array[indexCounter] == arr;
                    indexCounter++;
                }
            }
        }
    }   

    printf("array is %d", array);
    return array;
};


int main() {
// 10 x 10 grid. 1 denotes start. 2 denotes end.

    int grid[10][10] = {
        {0,0,0,0,0,2,0,0,0,0},
        {0,0,0,0,0,0,0,0,0,0},
        {0,0,0,0,0,0,0,0,0,0},
        {0,0,0,0,0,0,0,0,0,0},
        {0,0,0,0,0,0,0,0,0,0},
        {0,0,0,0,0,0,0,0,0,0},
        {0,0,0,0,0,0,0,0,0,0},
        {0,0,0,0,0,0,0,0,0,0},
        {0,0,0,0,0,0,0,0,0,0},
        {0,0,0,0,0,1,0,0,0,0},
        } ;
    search(grid, 5,9);
    firstArr(grid,5,9);
    return 0;
};