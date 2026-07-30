class Solution {
    
public:
int maxSubArray(vector<int>& nums) {
    int curr = 0;
    int result = INT_MIN;

    for (int n : nums) {
        // Either extend the previous subarray or start a new one at n.
        curr = max(curr + n, n);

        // Record the best subarray seen so far.
        result = max(result, curr);
    }

    return result;
}
};
