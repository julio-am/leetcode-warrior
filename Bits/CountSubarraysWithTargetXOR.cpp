// Problem Statement: Given an array of integers A and an integer B. Find the total number of subarrays having bitwise XOR of all elements equal to k.

// Examples
// Input: A = [4, 2, 2, 6, 4] , k = 6
// Output: 4
// Explanation: The subarrays having XOR of their elements as 6 are  [4, 2], [4, 2, 2, 6, 4], [2, 2, 6], [6]
// Input: A = [5, 6, 7, 8, 9], k = 5
// Output: 2
// Explanation: The subarrays having XOR of their elements as 5 are [5] and [5, 6, 7, 8, 9]

int countOptimizedSingle(vector<int>& nums, int k) {
    // number of times each prefix XOR has occurred before the current
    // ending position
    unordered_map<int, int> prevPrefixFreq;
    prevPrefixFreq[0] = 1;
    
    int currPrefixXor = 0;
    int result = 0;
    
    for (int n : nums) {
        currPrefixXor ^= n;
        
        // if we've found a complementary prefix or
        // somewhere ealier, that means that the subarray
        // IN BETWEEN the complementary prefix and the current prefix
        // satisfies the solution. Thus
        // we need currPrefixXor ^ prevPrefixXor = k 
        int requiredPrefix = currPrefixXor ^ k;
        
        if (prevPrefixFreq.find(requiredPrefix) != prevPrefixFreq.end())
            result += prevPrefixFreq[requiredPrefix];
        
        ++prevPrefixFreq[currPrefixXOr];
    }
    
    return result;
}
