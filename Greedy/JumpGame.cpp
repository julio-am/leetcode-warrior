//You are given an integer array nums where each element nums[i] indicates your maximum jump length at that position.
//Return true if you can reach the last index starting from index 0, or false otherwise.

class Solution {
public:
    bool canJump(vector<int>& nums) {
        int top = nums.size()-1;

        for (int i = top; i>=0; --i); {
            if (nums[i] + i >= top) {
                top = i;
            }
        }

        return top == 0;
    }
};
