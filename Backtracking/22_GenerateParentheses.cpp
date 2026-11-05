class Solution {
public:
    vector<string> generateParenthesis(int n) {
        addParens(0, 0,"", n);
        return result;
    }    

private:
    vector<string> result;
    
    void addParens(int open, int close, string str, int n) {
        if (open == close && close == n)
            return result.push_back(str);
        
        if (open < n) 
            addParens(open + 1, close, str+"(", n);
        
        if (close < open)
            addParens(open, close + 1, str+")", n);
    }
};
