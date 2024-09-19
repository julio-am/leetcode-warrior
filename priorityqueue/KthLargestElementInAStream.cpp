//Design a class to find the kth largest integer in a stream of values, including duplicates. E.g. the 2nd largest from [1, 2, 3, 3] is 3. The stream is not necessarily sorted.

//Implement the following methods:

//constructor(int k, int[] nums) Initializes the object given an integer k and the stream of integers nums.
//int add(int val) Adds the integer val to the stream and returns the kth largest integer in the stream.

class KthLargest {

private: 
    priority_queue<int, vector<int>, greater<int>> p;
    int n;

public:
    KthLargest(int k, vector<int>& nums) : n(k) {
        for (int num : nums)
            add(num);
    }
    
    int add(int val) {
        p.push(val);
        if (p.size() > n) {
            p.pop();
        }
        return p.top();
    }
};
