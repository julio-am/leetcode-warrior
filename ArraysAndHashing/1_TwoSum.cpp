class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        // value, index
        unordered_map<int, int> seen;

        for (int i = 0; i < nums.size(); ++i) {
            int curVal = nums[i];
            int prevVal = target - curVal;

            // we can optimize performance by prepopulating the array
            // to avoid iterationg. 
            if (seen.find(prevVal) != seen.end()) {
                return {seen[prevVal], i};
            }

            seen[curVal] = i;
        }

        return {};
    }
};
