class Solution {
public:
    vector<int> getAverages(vector<int>& nums, int k) {
        vector<int> result(nums.size(), -1);
        const int windowSize = 2*k + 1;

        if (windowSize > nums.size()) return result;

        // Make sure to use LL for the initial accumulation storage. 
        long long sum = accumulate(nums.begin(), nums.begin()+windowSize, 0LL);

        for (int center = k; center < nums.size()-k; ++center) {
            result[center] = sum / windowSize;

            if (center + k + 1 < nums.size()) {
                sum -= nums[center-k];
                sum += nums[center+k+1];
            }
        }

        return result;
    }
};
