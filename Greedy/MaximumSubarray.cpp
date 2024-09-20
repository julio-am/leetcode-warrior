class Solution {
public:
    
    int maxSubArray(vector<int>& nums) { 
        int curr = nums[0];
        int result = curr;

        for (int i = 1; i<nums.size(); ++i) {
            curr = max(curr+nums[i], nums[i); //choose to either use prefix or not
            result = max(result, curr); //choose to either use previous result or current
        }

        return result;
    }


  //alternately
  int maxSubArray(vector<int>& nums) { 
      int curr = nums[0];
      int result = curr;

      for (int i = 1; i<nums.size(); ++i) {
          if (curr < 0) curr = 0;
          curr += nums[i];
          result = max(result, curr);
      }
  
      return result;
  }

};
