class Solution {
public:
    int findMin(vector<int> &nums) {
        int l = 0, r = nums.size()-1, res = INT_MAX;

        while (l <= r) {
            int m = l + (r-l) / 2;
            
            // if the leftmost value is smaller than the rightmost value,
            // our current search window is propely sorted. so we return early.
            if (nums[l] < nums[r]) return min(res, nums[l]);
 
            res = min(res, nums[m]);

            // If the array is not sorted, but
            // the middle value is bigger than the left value, the pivot must be 
            // on the right side, since all values on the right of the pivot must be 
            // smaller than all values on the left of the pivot. 
            if (nums[m] >= nums[l]) l = m+1; 

            // If the middle value is smaller than the left value, the pivot mu16string
            // be somewhere to the left of the middle value.
            else r = m-1;
        }

        return res;
    }
};
