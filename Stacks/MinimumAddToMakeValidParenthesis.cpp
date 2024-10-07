//A parentheses string is valid if and only if:

//It is the empty string,
//It can be written as AB (A concatenated with B), where A and B are valid strings, or
//It can be written as (A), where A is a valid string.

//You are given a parentheses string s. In one move, you can insert a parenthesis at any position of the string.
//Return the minimum number of moves required to make s valid.
  
class Solution {
public:
    int minAddToMakeValid(string s) {
        int freeOpens = 0, freeCloses = 0;

        for (auto c : s) {
            if (c == '(') ++freeOpens;

            if (c == ')') {
                if (freeOpens) --freeOpens;
                else ++freeCloses;
            }
        }

        // need to insert parenthesis to match both the left over opens and left over closes.
        return freeOpens + freeCloses;
    }
};
