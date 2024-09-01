// Given an array of integers nums, return the length of the longest consecutive sequence of elements.
// A consecutive sequence is a sequence of elements in which each element is exactly 1 greater than the previous element.
// You must write an algorithm that runs in O(n) time.

class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        if (nums.size() == 0) return 0;

        // Creaete a set containing all our numbers
        unordered_set<int> numSet;
        for (auto num : nums) {
            numSet.insert(num);
        }

        // If a number is the start of a sequence (the previous number doesn't exist),
        //count the length of the sequence
        int largestLength = 1;
        for (auto num : nums) {
            if (numSet.find(num-1) == numSet.end()) {
                int currentLength = 1;
                while (numSet.find(num+currentLength) != numSet.end()) {
                    currentLength += 1;
                }
                largestLength = max(largestLength, currentLength);
            }
        }

        return largestLength;
    }
};
