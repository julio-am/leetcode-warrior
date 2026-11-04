class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int result = 0;
        int currentSum = 0;
        std::map<int, int> prefixSums;

        //Initialize base case 
        prefixSums[0] = 1;

        for (int i : nums) {
            currentSum += i;
            int diff = currentSum - k;
            result += prefixSums[diff];
            prefixSums[currentSum]++;
        }

        return result;
    }
};