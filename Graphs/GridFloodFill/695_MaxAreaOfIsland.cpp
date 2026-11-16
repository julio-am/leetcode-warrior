//You are given a matrix grid where grid[i] is either a 0 (representing water) or 1 (representing land).
//An island is defined as a group of 1's connected horizontally or vertically. You may assume all four edges of the grid are surrounded by water.
//The area of an island is defined as the number of cells within the island.
//Return the maximum area of an island in grid. If no island exists, return 0.

class Solution {

public:
    int dfs(vector<vector<int>>& grid, int row, int col) {
        if (row < 0 || row >= grid.size() ||
            col < 0 || col >= grid[0].size() ||
            grid[row][col] == 0) return 0;

        grid[row][col] = 0;
        return 1 + dfs(grid, row+1, col)
                 + dfs(grid, row-1, col)
                 + dfs(grid, row, col+1)
                 + dfs(grid, row, col-1);
    }

    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int result = 0;

        for (int row = 0; row < grid.size(); ++row) {
            for (int col = 0; col < grid[0].size(); ++col) {
                result = max(result, dfs(grid, row, col));
            }
        }

        return result;
    }
};
