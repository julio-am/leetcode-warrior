/*
Given an array of non-negative integers arr, you are initially positioned at start index of the array.
When you are at index i, you can jump to i + arr[i] or i - arr[i], check if you can reach to any index with value 0.

Notice that you can not jump outside of the array at any time.
*/

class Solution {
public:
    bool canReach(vector<int>& arr, int start) {
        // Base cases: if index out of bounds or already visited, return false
        if (start < 0 || start >= arr.size() || arr[start] == -1) return false;
        if (arr[start] == 0) return true;
              
        int left  = start - arr[start];
        int right = start + arr[start];
        
        // Mark current position as visited
        arr[start] = -1;
        
        // Check if we get to 0 through either a left or right jump recursively
        return canReach(arr, right) || canReach(arr, left);
    }
};
