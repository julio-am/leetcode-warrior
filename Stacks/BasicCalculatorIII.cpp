class Solution {

private:
    int findMatchingParenthesis(int i, string& s) {
        int balance = 0;
        for (i; i<s.size(); ++i) {
            if (s[i] == '(') ++balance;
            if (s[i] == ')') --balance;
            if (balance == 0) return i;
        }

        return -1;
    }

public:
    int calculate(string s) {
        stack<int> nums;

        int currNum = 0;
        char op = '+';

        for (int i = 0; i < s.size(); ++i) {
            if (s[i] == ')') {
                break;
            }

            if (s[i] == '(') {
                int endPos = findMatchingParenthesis(i, s);
                currNum = calculate(s.substr(i+1, endPos-i-1));
                i = endPos;
            }

            if (isdigit(s[i])) {
                currNum = (currNum * 10) + (s[i]-'0');
            }

            if ( (!isdigit(s[i]) && !iswspace(s[i])) || i == s.size()-1 ) {
                if (op == '+') {
                    nums.push(currNum);
                }
                if (op == '-') {
                    nums.push(-currNum);
                }
                if (op == '*') {
                    int prevNum = nums.empty() ? 0 : nums.top();
                    if (!nums.empty()) nums.pop();
                    nums.push(prevNum * currNum);
                }
                 if (op == '/') {
                    int prevNum = nums.empty() ? 0 : nums.top();
                    if (!nums.empty()) nums.pop();
                    nums.push(prevNum / currNum);
                }

                currNum = 0;
                op = s[i];
            }
        }

        int result = 0;
        while (!nums.empty()) {
            result += nums.top();
            nums.pop();
        }

        return result;
    }
};
