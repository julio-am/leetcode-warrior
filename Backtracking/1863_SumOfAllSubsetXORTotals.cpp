class Solution {
private:
int result = 0;

void helper(vector<int>& nums, int i, int cur) {
    if (i == nums.size()) {
        result += cur;
        return;
    }

    helper(nums, i+1, cur ^ nums[i]);
    helper(nums, i+1, cur);
}
