//You are given an array of integers candidates, which may contain duplicates, and a target integer target. Your task is to return a list of all unique combinations of candidates where the chosen numbers sum to target.
//Each element from candidates may be chosen at most once within a combination. The solution set must not contain duplicate combinations.
//You may return the combinations in any order and the order of the numbers in each combination can be in any order.

class Solution {
public:
    vector<vector<int>> result;
    vector<int> current;

    void dfs(vector<int>& nums, int target, int sum, int i) {
        if (sum == target) {
            result.push_back(current);
            return; // candidates[i] cannot be 0
        }
        if (sum > target || i >= nums.size()) {
            return;
        }

        // use nums[i]
        current.push_back(nums[i]);
        dfs(nums, target, sum+nums[i], i+1);
        current.pop_back();

        // skip all of num at i
        int j = i;
        while (j < nums.size() && nums[j] == nums[i]) {
            ++j;
        }

        dfs(nums, target, sum, j);
    }


    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        dfs(candidates, target, 0, 0);
        return result;
    }
};
