//Permutations

// The first level of the recursion swaps the first element with all possile options 
//  1, 2, 3, 4, 5, 6 
//  2, 1, 3, 4, 5, 6
//  3, 2, 1, 4, 5, 6   ...etc

// The second level repeats the same thing, but starting at the second element, for each of the above arrays
// 1, 2, 3, 4, 5, 6
// 1, 3, 2, 4, 5, 6
// 1, 4, 3, 2, 5, 6    ...etc

// This goes on until we've reached the last element, where we return since there's no longer anything to swap

//https://www.geeksforgeeks.org/write-a-c-program-to-print-all-permutations-of-a-given-string/

//================================
class Solution {

private:

vector<vector<int>> result;

void backtrack(vector<int>& nums, int l) {
    int r = nums.size()-1;

    // if we have reached the end of nums, append our current permutation and return.
    if (l == r) {
        result.push_back(nums);
        return;
    }

    // swap every rightward number into L, then do backtracking call on l+1.
    for (int i = l; i <= r; ++i) {
        swap(nums[l], nums[i]);
        backtrack(nums, l+1);
        swap(nums[l], nums[i]);
    }
}
