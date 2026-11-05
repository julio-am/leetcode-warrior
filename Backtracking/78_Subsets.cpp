class Solution {
// straightforward solution
// private:
// vector<vector<int>> results; 
// public:
//     vector<vector<int>> subsets(vector<int>& nums) {
//         vector<int> current;
//         addNums(nums, current, 0);
//         return results;
//     }
        
//     void addNums(vector<int>& nums, vector<int>& current, int i) {
//         if (i == nums.size()) {
//             results.push_back(current);
//             return;
//         }
        
//         current.push_back(nums[i]);
//         addNums(nums, current, i+1);
//         current.pop_back();
//         addNums(nums, current, i+1);
//     } 
        
    public:
    //optimal solution
        vector<vector<int>> results = {{}};
        
        for (int num : nums) {
            int size = results.size();
            for (int i = 0; i<size; ++i) {
                results.push_back(results[i]);
                results.back().push_back(num);
            }
        }
        return results;
    }
};