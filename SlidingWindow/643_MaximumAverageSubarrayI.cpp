class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {

        // use accumulate to build initial window in one step
        double sum = accumulate(nums.begin(), nums.begin()+k, 0);
        double result = sum;

        for (int i = k; i < nums.size(); ++i) {
            sum -= nums[i-k];
            sum += nums[i];
            result = max(result, sum);
        }

        return result/k;
    }
};
