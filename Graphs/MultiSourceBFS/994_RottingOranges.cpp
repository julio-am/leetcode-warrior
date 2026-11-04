class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        if (!grid.size()) return 0;

        int time = 0;
        int freshFruit = 0;
        queue<pair<int,int>> q;
        
        for (int row = 0; row < grid.size(); ++row) {
            for (int col = 0; col < grid[0].size(); ++col) {
                if (grid[row][col] == 2) {
                    q.push({row, col});
                }
                if (grid[row][col] == 1) {
                    ++freshFruit;
                }
            }
        }

        vector<pair<int,int>> dirs = {{1,0}, {-1,0}, {0,1}, {0,-1}};
        while (freshFruit > 0 && !q.empty()) {
            int timespan = q.size();
            for (int i = 0; i < timespan; ++i) {
                int row = q.front().first;
                int col = q.front().second;
                q.pop();

                for (auto dir : dirs) {
                    int newRow = row + dir.first;
                    int newCol = col + dir.second;

                    if (newRow >= 0 && newRow < grid.size() && newCol >= 0 && newCol < grid[0].size()
                        && grid[newRow][newCol] == 1) {                    
                        grid[newRow][newCol] = 2;
                        --freshFruit;
                        q.push({newRow, newCol});
                    }
                }       
            }
            ++time;
        }
        return freshFruit == 0 ? time : -1;
    }
};
