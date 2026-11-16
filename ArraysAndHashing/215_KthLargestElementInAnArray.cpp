class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        int max = INT_MIN, min = INT_MAX;
        for (auto n : nums) {
            max = std::max(max, n);
            min = std::min(min, n);
        }

        vector<int> freqs(max-min+1, 0);

        for (auto n : nums) {
            ++freqs[n-min];
        }

        for (int i = freqs.size()-1; i >= 0; --i) {
            k -= freqs[i];
            if (k <= 0) return i + min;
        }

        return -1;
    }
};
