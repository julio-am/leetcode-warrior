
//You are given a m×n 2D grid initialized with these three possible values:

//-1 - A water cell that can not be traversed.
//0 - A treasure chest.
//INF - A land cell that can be traversed. We use the integer 2^31 - 1 = 2147483647 to represent INF.

//Fill each land cell with the distance to its nearest treasure chest. If a land cell cannot reach a treasure chest than the value should remain INF.
//Assume the grid can only be traversed up, down, left, or right.
  
class Solution {

public:
    // start at each treasure and use bfs to increment the value 
    // of each adjacent land tile
    void islandsAndTreasure(vector<vector<int>>& grid) {
        if (!grid.size()) return;

        vector<vector<int>> result;
        queue<pair<int,int>> toVisit;

        for (int row = 0; row < grid.size(); ++row) {
            for (int col = 0; col < grid[0].size(); ++col) {
                if (grid[row][col] == 0) {
                    toVisit.push({row,col});
                }
            }
        }

        vector<pair<int,int>> dirs = {{-1,0}, {1,0}, {0,-1}, {0,1}};
        while (!toVisit.empty()) {
            int currRow = toVisit.front().first;
            int currCol = toVisit.front().second;
            toVisit.pop();

            for (auto dir : dirs) {
                int newRow = currRow + dir.first;
                int newCol = currCol + dir.second;

                if (newRow < 0 || newRow >= grid.size() ||
                    newCol < 0 || newCol >= grid[0].size() ||
                    grid[newRow][newCol] != INT_MAX) {
                        continue;
                }

                grid[newRow][newCol] = 1 + grid[currRow][currCol];
                toVisit.push({newRow,newCol});
            }
        }
        return;
    }
};
