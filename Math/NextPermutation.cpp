//A permutation of an array of integers is an arrangement of its members into a sequence or linear order.

//For example, for arr = [1,2,3], the following are all the permutations of arr: [1,2,3], [1,3,2], [2, 1, 3], [2, 3, 1], [3,1,2], [3,2,1].
//The next permutation of an array of integers is the next lexicographically greater permutation of its integer. More formally, if all the permutations of the array are sorted in one container according to their lexicographical order, then the next permutation of that array is the permutation that follows it in the sorted container. If such arrangement is not possible, the array must be rearranged as the lowest possible order (i.e., sorted in ascending order).

//For example, the next permutation of arr = [1,2,3] is [1,3,2].
//Similarly, the next permutation of arr = [2,3,1] is [3,1,2].
//While the next permutation of arr = [3,2,1] is [1,2,3] because [3,2,1] does not have a lexicographical larger rearrangement.
//Given an array of integers nums, find the next permutation of nums.

//The replacement must be in place and use only constant extra memory.

class Solution {
public:
    void nextPermutation(vector<int>& nums) {

        for (int pivot = nums.size()-1; pivot>0; --pivot) {

            // once we find the first number that isn't increasing
            if (nums[pivot-1] < nums[pivot]) {
                // find first bigger element from the right side to swap with
                int i = nums.size()-1;
                while (nums[i] <= nums[pivot-1] && i>=pivot) {
                    --i;
                } 
                swap(nums[i], nums[pivot-1]);

                // since the elements to the right of the pivot are in increasing order
                // from right to left, reverse to minimize the number.
                reverse(nums.begin()+pivot, nums.end());

                return;
            }
        }

        // if this is the maximum value, just sort the whole array to restart;
        sort(nums.begin(), nums.end());
    }
};
