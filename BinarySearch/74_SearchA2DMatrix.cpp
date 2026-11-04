//You are given an m x n 2-D integer array matrix and an integer target.

//Each row in matrix is sorted in non-decreasing order.
//The first integer of every row is greater than the last integer of the previous row.
//Return true if target exists within matrix or false otherwise.

//Can you write a solution that runs in O(log(m * n)) time?
  
class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        // find row
        int top = 0;
        int bottom = matrix.size()-1;

        while (top <= bottom) {
            int pos = (top+bottom)/2;
            
            vector<int>& found = matrix[pos];
            if (found.front() <= target && found.back() >=target) break;
            else if (found.front() > target) bottom = pos-1;
            else if (found.back() < target) top = pos+1;
        }

        if (top>bottom) return false;

        // find col
        int left = 0;
        vector<int>& vec = matrix[(top+bottom)/2];
        int right = vec.size()-1;

        while (left <= right) {
            int pos = (left+right)/2;
            int found = vec[pos];

            if (found == target) return true;
            else if (found < target) left = pos+1;
            else if (found > target) right = pos-1;
        }

        return false;
    }
};
