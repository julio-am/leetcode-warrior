//Given an array of integers nums and an integer k, return the total number of subarrays whose sum equals to k.
//A subarray is a contiguous non-empty sequence of elements within an array.

class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        unordered_map<int,int> sumCount;

        sumCount[0] = 1;
        int sum = 0;
        int result = 0;
        for (auto n : nums) {
            sum += n;
            result += sumCount[sum-k];
            ++sumCount[sum];
        }

        return result;
    }
};
