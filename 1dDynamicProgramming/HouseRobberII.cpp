//You are given an integer array nums where nums[i] represents the amount of money the ith house has. The houses are arranged in a circle, i.e. the first house and the last house are neighbors.
//You are planning to rob money from the houses, but you cannot rob two adjacent houses because the security system will automatically alert the police if two adjacent houses were both broken into.
//Return the maximum amount of money you can rob without alerting the police.

class Solution {
private:
    int robHelper(vector<int>& nums) {
        int rob1 = 0, rob2 = 0;

        for (int n : nums) {
            int current = max(rob2, rob1+n);
            rob1 = rob2;
            rob2 = current;
        }

        return rob2;
    }

public:
    int rob(vector<int>& nums) {
        if (nums.size() == 1) return nums[0];
        
        vector<int> nums1(nums.begin(), nums.end()-1);
        vector<int> nums2(nums.begin()+1, nums.end());
        return max(robHelper(nums1), robHelper(nums2));
    }
};
