class Solution {
public:
    vector<int> resultsArray(vector<int>& nums, int k) {
        if (k == 1) return nums;

        vector<int> result(nums.size()-k+1, -1);

        // Keep count of the current number of consecutive elements
        int curSize = 1;
        
        for (int i = 1; i < nums.size(); ++i) {
            if (nums[i] == nums[i-1] + 1) {
                ++curSize;
                if (curSize >= k) result[i-k+1] = nums[i];
            }

            else curSize = 1;
        }

        return result;
    }
};
