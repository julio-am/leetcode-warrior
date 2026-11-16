class Solution {
public:
    int minSwaps(vector<int>& nums) {
        int minSwaps = INT_MAX;
        int totalOnes = accumulate(nums.begin(), nums.end(), 0);

        int onesCount = nums[0];
        int right = 0;

        for (int left = 0; left < nums.size(); ++left) {
            if (left != 0) onesCount -= nums[left-1];

            while (right - left + 1 < totalOnes) {;
                onesCount += nums[++right % nums.size()];
            }

            minSwaps = min(minSwaps, totalOnes - onesCount);
        }

        return minSwaps;
    }
};
