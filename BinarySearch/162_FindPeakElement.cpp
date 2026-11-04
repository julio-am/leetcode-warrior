//A peak element is an element that is strictly greater than its neighbors.
//Given a 0-indexed integer array nums, find a peak element, and return its index. If the array contains multiple peaks, return the index to any of the peaks.
//You may imagine that nums[-1] = nums[n] = -∞. In other words, an element is always considered to be strictly greater than a neighbor that is outside the array.
//You must write an algorithm that runs in O(log n) time.

class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        int l = 0;
        int r = nums.size()-1;

        while (l < r) {
            int mid = (l+r) / 2;
            
            // if we're in the middle of a rising path, keep following it
            if (nums[mid] < nums[mid+1])
                l = mid+1;

            // otherwise, go backwards
            else
                r = mid;
        }

        // eventually we will scoot backwards into the left pointer.
        return l;
    }
};
