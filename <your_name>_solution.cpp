#include <vector>
#include <iostream>

class Solution {
public:
    int numIslands(std::vector<std::vector<char>>& grid) {
        int count = 0;
        // Your logic here
        
        return count;
    }

    // Helper function(s) to explore the grid
    
};

int main() {
    Solution solution;
    std::vector<std::vector<char>> grid = {
        {'1', '1', '0', '0', '0'},
        {'1', '1', '0', '0', '0'},
        {'0', '0', '1', '0', '0'},
        {'0', '0', '0', '1', '1'}
    };
    std::cout << "Number of Islands: " << solution.numIslands(grid) << std::endl;
    return 0;
}
