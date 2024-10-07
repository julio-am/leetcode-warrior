class Solution {
private: 
    void removeExtraCloses(char open, char close, string& s) {
        int balance = 0;

        for (int i = 0; i < s.size(); ++i) {
            if (s[i] == open) {
                ++balance;
            }

            if (s[i] == close) {
                if (balance == 0) {
                    s.erase(s.begin() + i--);
                }
                else {
                    --balance;
                }
            }
        }
    }


public:
    string minRemoveToMakeValid(string s) {
        // remove extra close parenthesis
        removeExtraCloses('(', ')', s);

        // remove extran open parenthesis going backwards
        reverse(s.begin(), s.end());
        removeExtraCloses(')', '(', s);
        reverse(s.begin(), s.end());

        return s;
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
