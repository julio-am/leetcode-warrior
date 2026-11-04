//You are given an integer array nums where nums[i] represents the amount of money the ith house has. The houses are arranged in a circle, i.e. the first house and the last house are neighbors.
//You are planning to rob money from the houses, but you cannot rob two adjacent houses because the security system will automatically alert the police if two adjacent houses were both broken into.
//Return the maximum amount of money you can rob without alerting the police.

class Solution {
private:
    int helper(vector<int>& nums, int start, int end) {
        int l = 0, r = 0;

        for (int i = start; i < end; ++i) {
            int next = max(r, l + nums[i]);
            l = r;
            r = next;
        }

        return r;
    }

public:
    int rob(vector<int>& nums) {
        if (nums.size() == 1) return nums[0];
        if (nums.size() == 2) return max(nums[0], nums[1]);

        int l = helper(nums, 0, nums.size()-1);
        int r = helper(nums, 1, nums.size());

        return max(l,r);
    }
};
