// Alternative implementations; submit one at a time.

// ============================================================================
// Approach 1 — original: Backtracking/permutations.cpp
// ============================================================================
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


// ============================================================================
// Approach 2 — original: SampleCode.cpp
// ============================================================================
Sample code
#include<vector>
class AllPermutations {
	private:
	    /*
	    takes an array, in and an index, ptr as input
		fixes all the terms before ptr
	    fixes all possible numbers at ptr by swapping each one of the terms ahead of ptr including ptr itself
	    calls permute(ptr+1,in)
	    swaps back to get the original in for next iteration of loop
	    */
	    void permute(std::vector<int> in, int startPosition) {
	        //end the recursion at ptr==n
	        if(ptr==in.size()) {
	            //store the permutation
	            res.push_back(in);
	            return;
	        }

	        //loop from ptr to last index of array
	        for(int i=startPosition; i<in.size(); ++i) {
	            //swap one of the possibilities

                //std::swap(in[startPos], in[i]);
	            int temp = in[startPosition];
	            in[startPosition] = in[i];
	            in[i] = temp;

                std::cout << in << std::endl;

	            //calling next recurrence
	            permute(in, startPosition+1);

	            //swapping back for next iteration of loop
	            temp = in[startPosition];
	            in[startPosition] = in[i];
	            in[i] = temp;
	        }
	        return;
	    }

	public:
	    //res to store all the permutation
	    std::vector<std::vector<int>> result;

	    /*
	    creates an array,in sorted ascending from 1 to n
	    calls permute from ptr=0 and array in
	    */
	    std::vector<std::vector<int>> getAll(int n) {
            std::vector<int> sortedArray;
	        for(int i=1; i<=n; ++i) {
	            sortedArray.push_back(i);
            }

        	permute(sortedArray, 0);
          return res;
	    }
};

