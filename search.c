#include <stdio.h>
#include <stdbool.h>

// declerations
int search(int[10][10], int, int);
bool outOfBounds(int, int);
int makeSearchArr(int[10][10], int, int, bool);
int expand(int[10][10], int[4][2], bool);


int search(int grid[10][10], int starty, int startx){
    printf("the strarting point, %d, axis' are\nx=%d & y=%d\n", grid[starty][startx], startx, starty);
    return 0;
};

// Checks if the x and y coordinates are within the 10x10 grid
bool outOfBounds(int x, int y) {
    if(x >= 0 && x < 10) {
        if(y >= 0 && y < 10) {
            return false;
        }
    }
    return true;
};

int makeSearchArr(int grid[10][10], int starty,int startx, bool found) {
      if(found == true) { 
        return 0;
    };     
     // adds count to loop over elements in array
    int indexCounter =0;
    // adds all the vertical and horizontal coordinates from the starting point. 
    // given a start of 9,5, the indexes array will contain {{5,8}, {4,9}, {6,9}, {5,10}}
    int indexes[4][2] = {{startx, starty-1}, {startx-1, starty}, {startx+1, starty}, {startx, starty+1}};
    int array[4][2];
    for( int i=0; i< 4; i++) {
            int x = indexes[i][0];
            int y = indexes[i][1];
            // checks if the coordinates are within grid
            if(outOfBounds(y,x) == false){
                // checks if the coordinates a passable value printf("%d", grid[5][9]);
                if(grid[y][x]==4) {
                    printf("found");
                    found = true;
                    return grid;
                }
                if(grid[y][x]== 0) {
                    array[indexCounter][0] = x;
                    array[indexCounter][1] = y;
                    indexCounter++;
                }
        }
    } 
    if(found == false) {
    expand(grid, array, found);
    }
};


int expand(int grid[10][10], int coordinatesArray[4][2], bool found ) {
    if(found == true) { 
        return grid;
    };
    for(int i = 0; i < 4; i++) {
        int x = coordinatesArray[i][0];
        int y = coordinatesArray[i][1];
        if (outOfBounds(y, x) == false){  
                if(found == false) {
                    if(grid[y][x] == 0) {
                    printf("grid[%d][%d]\n", y,x);
                    grid[y][x] = 2;
                    } 
                }
        }
    }
}


int main() {
// 10 x 10 grid. 1 denotes start. 2 denotes end.

    int grid[10][10] = {
        {0,0,0,0,0,0,0,0,0,0},
        {0,0,0,0,0,0,0,0,0,0},
        {0,0,0,0,0,0,0,0,0,0},
        {0,0,0,0,0,0,0,0,0,0},
        {0,0,0,0,0,0,0,0,0,0},
        {0,0,0,0,0,0,0,0,0,0},
        {0,0,0,0,0,4,0,0,0,0},
        {0,0,0,0,0,0,0,0,0,0},
        {0,0,0,0,0,0,0,0,0,0},
        {0,0,0,0,0,1,0,0,0,0},
        } ;
    bool found = false;
     printf("%d", grid[6][5]);
    search(grid, 9,5);
    makeSearchArr(grid, 9,5, found);
    
          printf("\ngrid:");
                    for(int i=0; i<10; i++) {
                        printf("\n");
                        for(int j=0; j<10; j++) { 
                            printf("%d", grid[i][j]);
                        }
                    }

    return 0;

};