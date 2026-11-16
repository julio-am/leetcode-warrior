//Given an integer array nums, return an array output where output[i] is the product of all the elements of nums except nums[i].
//Each product is guaranteed to fit in a 32-bit integer.
//Follow-up: Could you solve it in O(n) time without using the division operation?

class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        vector<int> result(nums.size());

        int prefix = 1;
        for (int i = 0; i < nums.size(); ++i) {
            result[i] = prefix;
            prefix *= nums[i];
        }

        int postfix = 1;
        for (int i = nums.size()-1; i >= 0; --i) {
            result[i] *= postfix;
            postfix *= nums[i];
        }

        return result;
    }
};
