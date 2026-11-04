class Solution {
public:
    int search(vector<int>& nums, int target) {
        int l = 0;
        int r = nums.size() - 1;
        
        
        while (l <= r) {
            int i = (l + r) / 2;
            
            if (nums[i] == target) return i;
            
            // if we're in the left portion
            if (nums[l] <= nums[i]) {
                // if we need to search the right portion
                if (target > nums[i] or target < nums[l])
                    l = i + 1;
                // if we need to search the left portion
                else 
                    r = i-1;
            }
            // if we're in the right portion
            else {
                if (target < nums[i] or  target > nums[r])
                    r = i-1;
                else 
                    l = i+1;
            }
        }
        return -1;
    }
};
