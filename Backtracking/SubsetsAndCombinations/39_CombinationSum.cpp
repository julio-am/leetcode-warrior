class Solution {
private:
    vector<vector<int>> results;
    
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        dfs(candidates, {}, 0, target, 0);
        return results;
    }
    
    void dfs(vector<int>& candidates, vector<int> result, int sum, int target, int i) {
        if (sum == target) {
            results.push_back(result);
            return;
        }
        
        if (sum > target || i >= candidates.size()) return;

        
        result.push_back(candidates[i]);
        dfs(candidates, result, sum+candidates[i], target, i);
        result.pop_back();
        
        dfs(candidates, result, sum, target, i+1);
    }
};
