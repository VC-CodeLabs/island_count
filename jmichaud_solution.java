public class IslandCounter {

    LandPosition[][] landPositions;

    public static class LandPosition {
        int row, col;
        int islandNumber;

        public LandPosition(int row, int col, int islandNumber) {
            this.row = row;
            this.col = col;
            this.islandNumber = islandNumber;
        }
    }

    public int numIslands(char[][] grid) {
        int count = 0;
        landPositions = new LandPosition[grid.length][grid[0].length];

        for (int row = 0; row < grid.length; row++) {
            for (int col = 0; col < grid[row].length; col++) {

                if (grid[row][col] == '1' && landPositions[row][col] == null) {
                    // land ho! previously undiscovered land, start an island then look around
                    count++;
                    LandPosition landPosition = new LandPosition(row, col, count);
                    landPositions[row][col] = landPosition;
                    explore(landPosition, grid);
                }
            }
        }
        return count;
    }

    private void explore(LandPosition startPosition, char[][] grid) {

        int row = startPosition.row;
        int col = startPosition.col;

        // look for undiscovered land to the east
        if (col < grid[row].length - 1 && grid[row][col+1] == '1' && landPositions[row][col+1] == null) {
            // new land!  claim it in the name of this island!
            LandPosition landPosition = new LandPosition(row, col+1, startPosition.islandNumber);
            landPositions[row][col+1] = landPosition;
            // keep going from here!
            explore(landPosition, grid);
        }

        // look south
        if (row < grid.length - 1 && grid[row+1][col] == '1' && landPositions[row+1][col] == null) {
            LandPosition landPosition = new LandPosition(row+1, col, startPosition.islandNumber);
            landPositions[row+1][col] = landPosition;
            explore(landPosition, grid);
        }

        // look west
        if (col > 0 && grid[row][col-1] == '1' && landPositions[row][col-1] == null) {
            LandPosition landPosition = new LandPosition(row, col-1, startPosition.islandNumber);
            landPositions[row][col-1] = landPosition;
            explore(landPosition, grid);
        }

        // look north
        if (row > 0 && grid[row-1][col] == '1' && landPositions[row-1][col] == null) {
            LandPosition landPosition = new LandPosition(row-1, col, startPosition.islandNumber);
            landPositions[row-1][col] = landPosition;
            explore(landPosition, grid);
        }
    }

    public static void main(String[] args) {
        IslandCounter solution = new IslandCounter();
        char[][] grid = {
                {'1', '1', '0', '0', '1'},
                {'1', '1', '0', '1', '0'},
                {'0', '0', '0', '0', '0'},
                {'1', '1', '1', '1', '1'},
                {'1', '0', '0', '0', '1'},
                {'1', '0', '1', '0', '1'},
                {'1', '0', '0', '0', '1'},
                {'1', '1', '1', '1', '1'}
        };
        System.out.println("Number of Islands: " + solution.numIslands(grid));

        for (int i = 0; i < solution.landPositions.length; i++) {
            for (int j = 0; j < solution.landPositions[i].length; j++) {
                if (solution.landPositions[i][j] == null)
                    System.out.print("0 ");
                else
                    System.out.print(solution.landPositions[i][j].islandNumber + " ");
            }
            System.out.println();
        }
    }
}
