class Solution {
public:
    int search(vector<int>& nums, int target) {
        int l = 0, r = nums.size()-1;

        while (l <= r) {
            int m = l + (r-l)/2;
            int found = nums[m];

            if (found == target) return m;
            if (found > target) r = m-1;
            if (found < target) l = m+1;
        }

        return -1;
    }
};
