class Solution {
public:    
    bool exist(vector<vector<char>>& board, string word) {
        if (word == "") return false;

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