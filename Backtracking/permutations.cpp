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

template<class T>
class Permuter {

  private:
    // Array to store the answer 
    std::vector<std::vector<T> > result;

    // Computes all permutations of a given array
    void permute(std::vector<T> arr, int l, int r) {
      // Base case
      if (l == r) {
          result.push_back(arr);
      }

      // Make permutation
      for int (i=l; i<=r; ++i) {
          // Swap start and the current position
          swap(arr[l], arr[i]);

          // recurse on the next segment
          permute(arr, l+1, r)

          swap(arr[l], arr[i]);
      }
    }


  public:

    std::vector<std::vector<T> > getPermutations(std::vector<T> arr) {
      permute(arr, 0, arr.size());    
      return result;    
    }
};


--------------------------------------


void permute(vector<int> arr, int start, int end) {
  if (l == r) {
    results.push_back(arr);
  }

  else (
    for (int i = start; i <= end; ++i) {
      arr.swap(i, start);
      permute(arr, start+1, end);
      arr.swap(i, start);
    }
  )
}

------------------------------------

class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        if (nums.size() == 0) return {{}};

        vector<int> remaining_nums(nums.begin() + 1, nums.end());
        vector<vector<int>> perms = permute(remaining_nums);
        vector<vector<int>> result;

        for (auto perm : perms) {
            for (int i = 0; i <= perm.size(); ++i) {
                perm.insert(perm.begin()+i, nums[0]);
                result.push_back(perm);
                perm.erase(perm.begin()+i);
            }
        }

        return result;
    }
};
