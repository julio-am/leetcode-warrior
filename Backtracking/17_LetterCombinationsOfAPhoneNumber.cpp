//You are given a string digits made up of digits from 2 through 9 inclusive.
//Each digit (not including 1) is mapped to a set of characters as shown below:
//A digit could represent any one of the characters it maps to.
//Return all possible letter combinations that digits could represent. You may return the answer in any order.

class Solution {
private:
    unordered_map<char, vector<char>> phone = {
        {'1', {}},
        {'2', {'a','b','c'}},
        {'3', {'d','e','f'}},
        {'4', {'g','h','i'}},
        {'5', {'j','k','l'}},
        {'6', {'m','n','o'}},
        {'7', {'p','q','r','s'}},
        {'8', {'t','u','v'}},
        {'9', {'w','x','y','z'}},
        {'0', {}}
    };

    vector<string> result;

    void backtrackHelper(string curr, string digits) {
        if (digits.size() == 0) {
            result.push_back(curr);
            return;
        }

        for (auto c : phone[digits[0]]) {
            backtrackHelper(curr+c, digits.substr(1));
        }
    }

public:
    vector<string> letterCombinations(string digits) {
        if (digits.size() == 0) return {};
        backtrackHelper("", digits);
        return result;
    }
};
