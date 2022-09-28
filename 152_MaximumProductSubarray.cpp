class Solution {
  
public:
    // Keep track of the current minimum and maximum possible values while
    // iterating through nums. Return the global maximum value.
    int maxProduct(vector<int>& nums) {
        int currMin = 1;
        int currMax = 1;
        int result = nums[0];
        
        for (int n : nums) {
            int minMult = n * currMin;
            int maxMult = n * currMax;
            
            currMin = min({minMult, maxMult, n});
            currMax = max({minMult, maxMult, n});
            
            result = max(currMax, result);
        }
        return result;
    }
};
