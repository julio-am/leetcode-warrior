class Solution {
public:
    bool isValid(string s) {
        stack<char> parens;
        
        for (char c : s) {
            if (c == '{' || c == '[' || c == '(')
                parens.push(c);
            
            if (c == '}' || c == ']' || c == ')') {
                if (parens.empty()) return false;
                char popped = parens.top();
                parens.pop();
                
                if (c == '}' && popped != '{') return false;
                if (c == ')' && popped != '(') return false;
                if (c == ']' && popped != '[') return false;
            }
        }
        return parens.empty();
    }
};