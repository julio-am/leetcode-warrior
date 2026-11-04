class Solution {
public:

    // Optimal: Boyer moore voting algorithm
    int majorityElement(vector<int>& nums) {
        int result = 0, count = 0;

        for (auto num : nums) {
            if (count == 0) result = num;
            count += (num == result) ? 1 : -1;
        }

        return result;
    }

  // easy sorting way
  int majorityElementSorting(vector<int>& nums) {
     sort(nums.begin(), nums.end());
     return nums[nums.size()/2];
  }
};
