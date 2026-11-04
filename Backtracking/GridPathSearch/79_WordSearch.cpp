// Alternative implementations; submit one at a time.

// ============================================================================
// Approach 1 — original: BFS/79_WordSearch.cpp
// ============================================================================
class Solution {
public:    
    bool exist(vector<vector<char>>& board, string word) {
        int numRows = board.size();
        int numCols = numRows ? board[0].size() : 0;
        
        for (int row = 0; row < numRows; ++row) 
            for (int col = 0; col < numCols; col++) 
                if (board[row][col] == word[0] && dfs(board, word, row, col, numRows, numCols, 0))
                    return true;
        
        return false;
    }

private:
    bool dfs(vector<vector<char>>& board, string word, int row, int col, int numRows, int numCols, int n) {
        if (n == word.size()) return true; 
        
        if (row < 0 || row >= numRows ||
            col < 0 || col >= numCols || 
            board[row][col] != word[n]) return false;
        
		board[row][col] = '0';
        
		bool result = dfs(board, word, row + 1, col, numRows, numCols, n + 1) ||
                      dfs(board, word, row - 1, col, numRows, numCols, n + 1) ||
                      dfs(board, word, row, col + 1, numRows, numCols, n + 1) ||
                      dfs(board, word, row, col - 1, numRows, numCols, n + 1);
        
		board[row][col] = word[n];
        return result;
    }
};

// ============================================================================
// Approach 2 — original: Backtracking/SearchForWord.cpp
// ============================================================================
//Given a 2-D grid of characters board and a string word, return true if the word is present in the grid, otherwise return false.
//For the word to be present it must be possible to form it with a path in the board with horizontally or vertically neighboring cells. The same cell may not be used more than once in a word.

class Solution {
private:
    
    bool dfs(int row, int col, vector<vector<char>>& board, string word) {
        if (word.size() == 0) return true;
        if (row < 0 || row >= board.size() ||
            col < 0 || col >= board[0].size() ||
            board[row][col] != word[0]) return false;

        board[row][col] = '!';
        if (dfs(row+1, col, board, word.substr(1)) ||
            dfs(row-1, col, board, word.substr(1)) ||
            dfs(row, col+1, board, word.substr(1)) ||
            dfs(row, col-1, board, word.substr(1))) return true;
        
        board[row][col] = word[0];
        return false;
    }

public:
    bool exist(vector<vector<char>>& board, string word) {
    
        for (int row = 0; row < board.size(); ++row) {
            for (int col = 0; col < board[0].size(); ++col) {
                if (board[row][col] == word[0]) {
                    if (dfs(row, col, board, word)) return true;
                }
            }
        }

        return false;
    }
};

