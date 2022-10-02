// Stair climbing problem
// You are climbing a staircase. It takes n steps to reach the top.

// Each time you can either climb 1 or 2 steps. In how many distinct ways can you climb to the top?


class Solution {
public:
    
    //basic
//    int climbStairs(int n) {
//        int dp[n+1];
//        dp[n] = 1;
//        dp[n-1] = 1;
//        
//        for (int i = n-2; i>=0; --i) {
//            dp[i] = dp[i+1] + dp[i+2];
//        }
//        return dp[0];
//    }
  
    
    //advanced
    int climbStairs(int n) {
        // Edge Cases
        if (n == 0 || n == 1) {
            return 1;
        }
        
        int twoStepsUp = 1;
        int oneStepUp = 1;
        int currentStep;
        
        for (int i = n-2; i>=0; --i) {  //<- could I just do while n >= 0 here?
            currentStep = twoStepsUp+oneStepUp;
            twoStepsUp = oneStepUp;
            oneStepUp = currentStep;
        }
        return currentStep;
    }
};