// 240220CodeLab.cpp : This file contains the 'main' function. Program execution begins and ends there.
/*
Below is the challenge for this week; remember to think about the edge cases.Here’s some of them :

-Grid is all water.
- Grid is all land.
- An Island surrounded by water which is surrounded by another island.

If you think of any edge cases, feel free to share them and help everyone else consider them.


Island Count
Given an m x n 2D binary grid which represents a map of '1's(land) and '0's(water), return the number of islands.
An island is surrounded by water and is formed by connecting adjacent lands horizontally or vertically.You may assume all four edges of the grid
are all surrounded by water.


Example 1:
Input: grid = [
["1", "1", "1", "1", "0"],
["1", "1", "0", "1", "0"],
["1", "1", "0", "0", "0"],
["0", "0", "0", "0", "0"]
]

Output : 1


Example 2 :
Input : grid = [
["1", "1", "0", "0", "0"],
["1", "1", "0", "0", "0"],
["0", "0", "1", "0", "0"],
["0", "0", "0", "1", "1"]
]

Output : 3


Constraints :
m == grid.length
n == grid[i].length
1 <= m, n <= 300
grid[i][j] is '0' or '1'.


Submission Guidelines : You can either email me your submission or Fork the Repository and create a pull request.
To submit using the GitHub repository, you must fork the challenge repository and create a Pull Request with your solution.
Code Your Solution : In your chosen high - performance language.Remember, efficiency is key!
Naming Convention : Name your solution file using the following convention : <your_name>_solution.* (replace <your_name> with your actual name and *with the appropriate file extension for your language).

All merge requests will remain open and un - merged until Monday morning.


Winner Selection :
Criteria Correctness : Solutions must pass all test cases.
Performance : Among the correct solutions, the winning solution will be the one with the fastest execution time.


Submission Deadline :
All email solutions or merge requests must be submitted by Sunday at 23 : 59 : 59.
*/

#include <cstdio>
#include <cstdlib>
#include <time.h>
#include <atlstr.h>
#include <stdio.h>
#include <stdlib.h>

enum Val {SEA=0, LAND=1};

struct Node
{
    Val value;
    int islandNumber;
    Node* pNeighbor[4];
    int lastKey;
};

int GetExistingIslandNumber(Node *pStart, int key);

int main()
{
    // Set up input array test cases
    // Set up for maximum size.  More elegant to dynamically create but time consuming.
    
    #define ROWS 1
    #define COLS 40

    Node nodes[ROWS][COLS];

    /*
    char grid[ROWS][COLS] =
    {
        {'1', '1', '1', '1', '0'},
        {'1', '1', '0', '1', '0'},
        {'1', '1', '0', '0', '0'},
        {'0', '0', '0', '0', '0'}
    };  // Output=1
    */

    /*
    char grid[ROWS][COLS] =
    {
        {'1', '1', '0', '0', '0'},
        {'1', '1', '0', '0', '0'},
        {'0', '0', '1', '0', '0'},
        {'0', '0', '0', '1', '1'}
    };  // Output=3
    */

    /*
    char grid[ROWS][COLS] =
    {
        {'0'}
    };  // Output=0
    */

    /*
    char grid[ROWS][COLS] =
    {
        { '1', '1', '1', '1', '1' },
        { '1', '0', '1', '1', '1' },
        { '1', '0', '0', '0', '1' },
        { '1', '0', '1', '0', '1' },
        { '1', '0', '0', '1', '1' }
    };  // Output = 2
    */

    char grid[ROWS][COLS] =  // 1x40
    {
        { '1', '1', '1', '0', '1', '0', '0', '0', '0', '0', '1', '1', '1', '1', '0', '1', '1', '1', '0', '0', '1', '1', '0', '1', '1', '1', '0', '1', '1', '0', '0', '1', '1', '0', '1', '1', '1', '0', '1', '1' }
    };  // Output=10

    // Variables
    int m = ROWS, n = COLS, output = 0, i, j, k, exist, key = 0;

    // Code to generate and print a random array (used for testing)
    /*
    char grid[ROWS][COLS];
    srand((unsigned int)time(NULL));
    for (i = 0; i < m; i++)
        for (j = 0; j < n; j++)
            grid[i][j] = rand() % 2 + '0'; // Get a zero or 1 char
    printf("{\n");
    for (i = 0; i < m; i++)
    {
        for (j = 0; j < n; j++)
        {
            if (j == 0)
                printf("    { ");
            if (j < n-1)
                printf("'%c', ", grid[i][j]);
            else if (j == n-1)
                printf("'%c' }", grid[i][j]);
        }
        if (i == m-1)
            printf("\n");
        else
            printf(",\n");
    }
    printf("};\n");
    */

    // Initialize
    memset(nodes, 0, sizeof(Node) * m * n);  // quick way to initialize nodes to all zeros
    for (i = 0; i < m; i++)
    {
        for (j = 0; j < n; j++)
        {
            if (grid[i][j] == '1') nodes[i][j].value = LAND;
            // else leave at zero, which is for SEA

            // Set up neighbor pointers (leave NULLS for edges)
            if (i > 0)      nodes[i][j].pNeighbor[0] = &nodes[i - 1][j];  // North
            if (i < m-1)    nodes[i][j].pNeighbor[1] = &nodes[i + 1][j];  // South
            if (j > 0)      nodes[i][j].pNeighbor[2] = &nodes[i][j - 1];  // East
            if (j < n-1)    nodes[i][j].pNeighbor[3] = &nodes[i][j + 1];  // West
        }
    }

    // Go through the analysis starting with the upper left corner
    for (i = 0; i < m; i++)  // Rows
    {
        for (j = 0; j < n; j++)  // Columns
        {
            // If this node is land and not assigned an island yet then analyze (if sea then nothing needs to be done)
            if (nodes[i][j].value == LAND && nodes[i][j].islandNumber == 0)
            {
                key++;
                exist = GetExistingIslandNumber(&nodes[i][j], key);

                // If this piece of land is not linked to an existing island then create a new island
                // If it is linked then use that island number
                if (exist == 0)
                    nodes[i][j].islandNumber = ++output;
                else
                    nodes[i][j].islandNumber = exist;
            }
        }
    }

    // Output nodes for debugging
    /*
    printf("[\n");
    k;
    for (i = 0; i < m; i++)
    {
        for (j = 0; j < n; j++)
        {
            printf("[%p - %d %d - ",
                &nodes[i][j], (int)nodes[i][j].value, nodes[i][j].islandNumber);
            for (k = 0; k < 4; k++)
            {
                if (k == 3)
                    printf("%p]\n", nodes[i][j].pNeighbor[k]);
                else
                    printf("%p   ", nodes[i][j].pNeighbor[k]);
            }
        }
        printf("\n");
    }
    printf("]\n");
    */
    
    // Output result
    printf("\nOutput = %d\n", output);
    return(0);
}

// Function to recurse through the network of nodes following land to get the island number if it exists
int GetExistingIslandNumber(Node* pStart, int key)
{
    int k,exist = 0;

    pStart->lastKey = key;

    if (pStart->islandNumber != 0)
        return(pStart->islandNumber);

    for (k = 0; k < 4; k++)
    {
        if (pStart->pNeighbor[k] != NULL && pStart->pNeighbor[k]->value == LAND && pStart->pNeighbor[k]->lastKey != key)
            exist = GetExistingIslandNumber(pStart->pNeighbor[k], key);
        if (exist != 0)
            break;
    }
    return(exist);
}
