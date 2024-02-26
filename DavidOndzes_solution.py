def numIslands(grid):
    if not grid:
        return 0
    
    def depthFirstSearch(i, j):
        print("dfs(", i, ", ", j)
        if i < 0 or i >= len(grid) or j < 0 or j >= len(grid[0]) or grid[i][j] == '0':
            return
        grid[i][j] = '0'  # Mark as visited
        # Visit neighbors
        depthFirstSearch(i+1, j)
        depthFirstSearch(i-1, j)
        depthFirstSearch(i, j+1)
        depthFirstSearch(i, j-1)
    
    islands = 0
    for i in range(len(grid)):
        for j in range(len(grid[0])):
            if grid[i][j] == '1':
                islands += 1
                depthFirstSearch(i, j)
    
    return islands

# Test cases
grid1 = [
    ["1","1","1","1","0"],
    ["1","1","0","1","0"],
    ["1","1","0","0","0"],
    ["0","0","0","0","0"]
]
#print(numIslands(grid1))

grid2 = [
    ["1","1","0","0","0"],
    ["1","1","0","0","0"],
    ["0","0","1","0","0"],
    ["0","0","0","1","1"]
]
#print(numIslands(grid2))
