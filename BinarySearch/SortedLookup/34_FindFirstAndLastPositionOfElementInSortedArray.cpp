class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        if (nums.size() == 0) return {-1,-1};

        int l = 0;
        int r = nums.size()-1;

        while (l < r) {
            int mid = l + (r - l) / 2;

            if (nums[mid] < target) l = mid+1;
            else r = mid;
        }

        int first = l;
        if (nums[first] != target) {
            return {-1, -1};
        }


        l = 0;
        r = nums.size(); //last index can be answer

        // decrement First index where r = target
        while (l < r) {
            int mid = l + (r - l) / 2;

            if (nums[mid] > target) r = mid;
            else l = mid+1;
        }

        int last = l-1;

        return {first, last};
    }
};
