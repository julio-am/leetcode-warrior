//Given an integer array nums, move all 0's to the end of it while maintaining the relative order of the non-zero elements.
//Note that you must do this in-place without making a copy of the array.

class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int numZeroes = 0;
        for (int i = 0; i < nums.size() - numZeroes; ++i) {
            if (nums[i] == 0) {
                nums.erase(nums.begin() + (i--));
                nums.push_back(0);
                ++numZeroes;
            }
        }
    }
};
