
//You are given a m×n 2D grid initialized with these three possible values:

//-1 - A water cell that can not be traversed.
//0 - A treasure chest.
//INF - A land cell that can be traversed. We use the integer 2^31 - 1 = 2147483647 to represent INF.

//Fill each land cell with the distance to its nearest treasure chest. If a land cell cannot reach a treasure chest than the value should remain INF.
//Assume the grid can only be traversed up, down, left, or right.
  
class Solution {

private:
vector<pair<int,int>> dirs = {{1,0}, {-1,0}, {0,1}, {0,-1}}; 


public:
    void wallsAndGates(vector<vector<int>>& grid) {
        vector<pair<int,int>> dirs = {{1,0}, {-1,0}, {0,1}, {0,-1}}; 
        queue<pair<int,int>> toVisit;

        // push every gate to the queue initially
        int numRows = grid.size();
        int numCols = numRows == 0 ? 0 : grid[0].size();

        for (int r = 0; r < numRows; ++r) {
            for (int c = 0; c < numCols; ++c) {
                if (grid[r][c] == 0) toVisit.push({r,c});
            }
        }


        int curDist = 0;

        while (!toVisit.empty()) {
            int queueSize = toVisit.size();

            for (int i = 0; i < queueSize; ++i) {
                auto [row, col] = toVisit.front();
                toVisit.pop();
                
                for (auto dir : dirs) {
                    int newRow = row + dir.first;
                    int newCol = col + dir.second;

                    if (newRow >= 0 && newRow < numRows &&
                        newCol >= 0 && newCol < numCols &&
                        grid[newRow][newCol] > curDist+1) {

                            grid[newRow][newCol] = curDist+1;
                            toVisit.push({newRow, newCol});
                    }
                }
            }

            ++curDist;
        }
    }
};
