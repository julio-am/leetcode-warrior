//You are given a string s which contains only three types of characters: '(', ')' and '*'.

//Return true if s is valid, otherwise return false.

//A string is valid if it follows all of the following rules:

//Every left parenthesis '(' must have a corresponding right parenthesis ')'.
//Every right parenthesis ')' must have a corresponding left parenthesis '('.
//Left parenthesis '(' must go before the corresponding right parenthesis ')'.
//A '*' could be treated as a right parenthesis ')' character or a left parenthesis '(' character, or as an empty string "".

class Solution {
public:
    bool checkValidString(string s) {
        // minLefts counts the minimum number of open left parens we have as pos i
        // maxLefts counts the max num of open left parens we have at pos i
        int minLefts=0, maxLefts=0;

        for (auto c : s) {
            if (c == '(') {
                ++maxLefts;
                ++minLefts;
            }

            if (c == ')') {
                --maxLefts;
                --minLefts;
            }

            if (c == '*') {
                ++maxLefts;
                --minLefts;
            }

            if (maxLefts < 0) return false;

            // don't purposefully choose a solution where we don't have enough
            // left parenthesis.
            minLefts = max(minLefts, 0);
        }

        return minLefts == 0;
    }
};
