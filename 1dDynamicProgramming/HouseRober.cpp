//You are given an integer array nums where nums[i] represents the amount of money the ith house has. The houses are arranged in a straight line, i.e. the ith house is the neighbor of the (i-1)th and (i+1)th house.
//You are planning to rob money from the houses, but you cannot rob two adjacent houses because the security system will automatically alert the police if two adjacent houses were both broken into.
//Return the maximum amount of money you can rob without alerting the police.

class Solution {
public:
    int rob(vector<int>& nums) {
        int rob1 = 0, rob2 = 0;

        for (auto n : nums) {  
            int current = max(rob2, n+rob1);
            rob1 = rob2;
            rob2 = current;
        }

        return rob2;
    }
};
