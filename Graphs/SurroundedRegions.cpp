//You are given a 2-D matrix board containing 'X' and 'O' characters.
//If a continous, four-directionally connected group of 'O's is surrounded by 'X's, it is considered to be surrounded.
//Change all surrounded regions of 'O's to 'X's and do so in-place by modifying the input board.

class Solution {
public:
    void dfs(int row, int col, vector<vector<char>>& board) {
        if (row < 0 || row >= board.size() ||
            col < 0 || col >= board[0].size() ||
            board[row][col] != 'O') return;

            board[row][col] = 'S';
            dfs(row+1, col, board);
            dfs(row-1, col, board);
            dfs(row, col+1, board);
            dfs(row, col-1, board);
    }

    void solve(vector<vector<char>>& board) {
        if (!board.size()) return;

        // start DFS from the outer corners of the grid. Change all seen squares to "S"
        
        // left,right
        for (int row = 0; row < board.size(); ++row) {
            dfs(row, 0, board);
            dfs(row, board[0].size()-1, board);
        }
        
        // top,bottom
        for (int col = 0; col < board[0].size(); ++col) {
            dfs(0, col, board);
            dfs(board.size()-1, col, board);
        }
        
        // Change all non-"S" squares to "X"
        for (int row = 0; row < board.size(); ++row) {
            for (int col = 0; col < board[0].size(); ++col) {
                if (board[row][col] != 'S') {
                    board[row][col] = 'X';
                }
            }
        }

        // change all "S" squares back to "O"
        for (int row = 0; row < board.size(); ++row) {
            for (int col = 0; col < board[0].size(); ++col) {
                if (board[row][col] == 'S') {
                    board[row][col] = 'O';
                }
            }
        }
    }
};
