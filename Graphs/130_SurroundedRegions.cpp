//You are given a 2-D matrix board containing 'X' and 'O' characters.
//If a continous, four-directionally connected group of 'O's is surrounded by 'X's, it is considered to be surrounded.
//Change all surrounded regions of 'O's to 'X's and do so in-place by modifying the input board.


class Solution {
public:
    // basically find all the positions that are connected to the edge and save 
    // them by marking them as '#'. Set everything else to X, then restore the saveed ones.
    void solve(vector<vector<char>>& board) {
        // top and bottom
        for (int col = 0; col < board[0].size(); ++col) {
            dfs(0, col, board);
            dfs(board.size()-1, col, board);
        }

        // left and right
        for (int row = 0; row < board.size(); ++row) {
            dfs(row, 0, board);
            dfs(row, board[0].size()-1, board);
        }

        for (int row = 0; row < board.size(); ++row) {
            for (int col = 0; col < board[0].size(); ++col) {
                if (board[row][col] == '#') board[row][col] = 'O';
                else board[row][col] = 'X';
            }
        }
    }

private:
    void dfs(int row, int col, vector<vector<char>>& board) {
        if (row < 0 || row >= board.size() ||
            col < 0 || col >= board[0].size() ||
            board[row][col] != 'O') return;

            board[row][col] = '#';

            dfs(row+1, col, board);
            dfs(row-1, col, board);
            dfs(row, col+1, board);
            dfs(row, col-1, board);
    }
};
