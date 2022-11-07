/* 1143. Longest Common Subsequence

Given two strings text1 and text2, return the length of their longest common subsequence.
If there is no common subsequence, return 0.

A subsequence of a string is a new string generated from the original string with some characters (can be none) deleted without changing the relative order of the remaining characters.

For example, "ace" is a subsequence of "abcde".
A common subsequence of two strings is a subsequence that is common to both strings.
*/

class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
        int grid[text1.length()+1][text2.length()+1];
      
        for (int i = text1.length(); i >= 0; --i)
            grid[i][text2.length()] = 0;
        for (int j = text2.length(); j>=0; --j)
                grid[text1.length()][j] = 0;
        
        for (int i = text1.length()-1; i >= 0; --i) {
            for (int j = text2.length()-1; j>=0; --j) {
                grid[i][j] = text1[i] == text2[j] ?
                    1+grid[i+1][j+1] :
                    max(grid[i+1][j], grid[i][j+1]);
            }
        }
        return grid[0][0];
    }
};