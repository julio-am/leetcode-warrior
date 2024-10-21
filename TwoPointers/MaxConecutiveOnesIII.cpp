//Given a binary array nums and an integer k, return the maximum number of consecutive 1's in the array if you can flip at most k 0's.

class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int result = 0;
        int zeroes = 0;
        int l = 0, r = 0;

        while (r < nums.size()) {
            if (nums[r] == 0) {
                ++zeroes;
            }

            while (zeroes > k && l <= r) {
                if (nums[l] == 0) {
                    --zeroes;
                }
                 ++l;
            }
            
            ++r;
            result = max(result, r - l);
            
        }

        return result;
    }
};
