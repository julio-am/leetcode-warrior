// Given an array, arr[] of N integers and 2 integers L and R, the task is to return the largest integer K greater than 0 and L<=K<=R, such that both values K and -K exist in array arr[]. If there is no such integer, then return 0. 

// Examples:
// Input: N = 5, arr[] = {3, 2, -2, 5, -3},  L = 2, R = 3
// Output: 3
// Explanation: The largest value of K in the range [2, 3] such that both K and -K exist in the array is 3 as 3 is present at arr[0] and -3 is present at arr[4].

// Input: N = 4, arr[] = {1, 2, 3, -4},  L = 1, R = 4
// Output: 0

int findLargestK(std::vector<int>& arr, int l, int r) {
    set<int> numSet;
    for (int n : arr) { numSet.insert(n); }
    
    for (int i = r; i >= l; --i) {
        if (numSet.find(i) != numSet.end() && numSet.find(i*-1) != numSet.end()) {
            return i;
        }
    }
    
    return 0;
}

int main() {
    vector<int> arr = {3, 2, -2, 5, -3};
    int l = 2;
    int r = 3;
    std::cout << findLargestK(arr, l, r) << std::endl;
    
    arr = {1, 2, 3, -4};
    l = 1;
    r = 4;
    std::cout << findLargestK(arr, l, r) << std::endl;
}