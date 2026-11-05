//You are given an array of integers nums, where nums[i] represents the maximum length of a jump towards the right from index i. For example, if you are at nums[i], you can jump to any index i + j where:

//j <= nums[i]
//i + j < nums.length
//You are initially positioned at nums[0].

//Return the minimum number of jumps to reach the last position in the array (index nums.length - 1). You may assume there is always a valid answer.


class Solution {
public:
    int jump(vector<int>& nums) {
        int count = 0, l = 0, r = 0;

        while (r < nums.size()-1) {
            int maxJump = 0;

            for (int i = l; i <= r; ++i) {
                maxJump = max(maxJump, i+nums[i]);
            }

            l = r+1;
            r = maxJump;
            ++count;
        }

        return count;
    }
};
