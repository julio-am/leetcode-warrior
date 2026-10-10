class Solution {
public:
    long long countSubarrays(vector<int>& nums, long long k) {
        long long result = 0;
        int left = 0;
        long long sum = 0;
        int length = 0;  

        for (int i = 0; i < nums.size(); ++i) {
            sum += nums[i];
            ++length;
            while (sum * length >= k && length >= 0) {
                sum -= nums[left++];
                --length;
            }

            result += length;
        }

        return result;
    }
};
