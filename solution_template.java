public class Solution {
    public int numIslands(char[][] grid) {
        int count = 0;
        // Your logic here
        
        return count;
    }

    // Helper function(s) to explore the grid
    
    public static void main(String[] args) {
        Solution solution = new Solution();
        char[][] grid = {
            {'1', '1', '0', '0', '0'},
            {'1', '1', '0', '0', '0'},
            {'0', '0', '1', '0', '0'},
            {'0', '0', '0', '1', '1'}
        };
        System.out.println("Number of Islands: " + solution.numIslands(grid));
    }
}
