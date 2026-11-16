#include<algorithm>
#include<deque>
#include<vector>
class SlidingWindowMinimum {
public:
  std::vector<int> getMinimums(std::vector<int> nums, int k){

    // vector to be returned
    std::vector<int> ans;

    int n = nums.size();

    // edge case
    if(k == 0 or k > n) return ans;
    // maintain a deque of size k
    std::deque<int> dq(k);
    // push first k elements to the deque
    for(int i = 0; i < k; i++)
    {
        // remove previous elements
        // greater than currently being added
        while(!dq.empty() && nums[i] <= nums[dq.back()])
            dq.pop_back();
        // push current element
        dq.push_back(i);
    }
    // push min element of first window to return list
    ans.push_back(nums[dq.front()]);
    // now slide the window by 1 until whole array is finished
    for(int i = k; i < n; i++)
    {
        // remove elements out of current window
        while(!dq.empty() && dq.front() <= i - k)
            dq.pop_front();
        // remove previous elements
        // greater than currently being added
        while(!dq.empty() && nums[i] <= nums[dq.back()])
            dq.pop_back();
        // push current element
        dq.push_back(i);
        // push min of current window to return list
        ans.push_back(nums[dq.front()]);
    }
    // return list
    return ans;
  }
};