// You are given an array nums of integers, which may contain duplicates. Return all possible subsets.
// The solution must not contain duplicate subsets. You may return the solution in any order.

class Solution {
public:
    vector<vector<int>> result;
    vector<int> subset;

    void dfs(vector<int>& nums, int i) {
        if (i >= nums.size()) {
            result.push_back(subset);
            return;
        }

        // Use nums[i]
        subset.push_back(nums[i]);
        dfs(nums, i+1);
        subset.pop_back();

        // skip the current number entirely
        int j = i+1;
        while (j<nums.size() && nums[j] == nums[i]) {
            ++j;
        }
        dfs(nums, j);
    }

    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        dfs(nums, 0);
        return result;
    }
};
