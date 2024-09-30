// Advanced solution 
class Solution {

private:
    // since we can immediately remove invalid closing parenthesis, leverage this in both directions
    string removeInvalidCloseString(string& s, char open, char close) {
        string result;
        int balance = 0;
        for (int i = 0; i<s.size(); ++i) {
            if (s[i] == open) ++balance;
            if (s[i] == close) {
                if (balance == 0) continue;
                --balance;
            }
            result.push_back(s[i]);
        }

        return result;
    }

public:
    string minRemoveToMakeValid(string s) {
        // remove invalid ')' in one forward pass
        string result = removeInvalidCloseString(s, '(', ')');

        // remove invalid '(' in one backward pass
        reverse(result.begin(), result.end());
        result = removeInvalidCloseString(result, ')', '(');

        // put the string back to right direction
        reverse(result.begin(), result.end());
        return result;
    }
};

///////////////////////////////////////////////////////////////////////////

// Simple solution
class Solution {
public:
    string minRemoveToMakeValid(string s) {
        stack<int> opens;
        set<int> toRemove;

        for (int i = 0; i<s.size(); ++i) {
            // if we find an open paren, add it to the stack
            if (s[i] == '(') opens.push(i);

            // if we find a close paren when the stack is empty, remove it.
            else if (s[i] == ')') {
                if (opens.empty()) {
                    toRemove.insert(i);
                }
                else {
                    opens.pop();
                }
            }
        }

        // if there are any leftover parenthesis at the end, add it to the set to Remove.
        while (!opens.empty()) {
            toRemove.insert(opens.top());
            opens.pop();
        }

        // create result string
        string result;
        for (int i = 0; i<s.size(); ++i) {
            if (toRemove.count(i)) {
                continue;
            }

            result += s[i];
        }

        return result;
    }
};
