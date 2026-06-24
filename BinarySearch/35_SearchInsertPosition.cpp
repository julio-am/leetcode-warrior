class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int l = 0, r = nums.size()-1;

        while (l <= r) {
            int mid = l + (r-l)/2;
            int found = nums[mid];

            if (found == target) return mid;
            if (found < target) l = mid+1;
            if (found > target) r = mid-1;
        }

        return l;
    }
};
