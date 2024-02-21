// Shea Durgin
#include <stdio.h>
#include <time.h>

#define ROWS 4
#define COLS 5

static int directions[4][2] = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};

void dfs(char grid[ROWS][COLS], int i, int j) {
    if (i < 0 || i >= ROWS || j < 0 || j >= COLS || grid[i][j] != '1') return;
    grid[i][j] = '0';
    for (int k = 0; k < 4; k++) 
        dfs(grid, i + directions[k][0], j + directions[k][1]);
}

int count(char grid[ROWS][COLS]) {
    int islands = 0;
    for (int i = 0; i < ROWS; i++)
        for (int j = 0; j < COLS; j++)
            if (grid[i][j] == '1') {
                islands++;
                dfs(grid, i, j);
            }
    return islands;
}

int main() {
    char grid[ROWS][COLS] = {
        {'1', '1', '0', '0', '0'},
        {'1', '1', '0', '0', '0'},
        {'0', '0', '1', '0', '0'},
        {'0', '0', '0', '1', '1'}
    };

    clock_t start_time = clock();
    
    int islands = count(grid);
    printf("%d\n", islands);

    printf("%f\n", (double)(clock() - start_time) / CLOCKS_PER_SEC);
    
    return 0;
}
