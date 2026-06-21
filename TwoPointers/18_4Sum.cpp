class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> result;

        // first loop
        for (int i = 0; i < nums.size()-3; ++i) {
            if (i > 0 && nums[i] == nums[i-1]) continue;

            // second loop
            for (int j = i+1; j < nums.size()-2; ++j) {
                if (j > i+1 && nums[j] == nums[j-1]) continue;

                // two pointers converging to answer
                int l = j+1, r = nums.size()-1;
                while (l < r) {
                    long long sum = (long long)nums[i] + nums[j] + nums[l] + nums[r];
                    if (sum < target) ++l;
                    if (sum > target) --r;
                    if (sum == target) {
                        result.push_back({nums[i], nums[j], nums[l], nums[r]});
                        --r;
                        ++l;
                        while (nums[l] == nums[l-1] && l < r) ++l;
                    }
                }
            }
        }
        return result;
    }
};
