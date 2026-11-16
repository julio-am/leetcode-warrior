class Solution {
public:
    int longestMonotonicSubarray(vector<int>& nums) {
        if (nums.size() == 0) return 0;
        
        int result = 1;
        int curDesc = 1;
        int curInc = 1;

        for (int i = 1; i < nums.size(); ++i) {
            curInc = nums[i] > nums[i-1] ? curInc+1 : 1;
            curDesc = nums[i] < nums[i-1] ? curDesc+1 : 1;

            result = max({result, curInc, curDesc});
        }

        return result;
    }
};
