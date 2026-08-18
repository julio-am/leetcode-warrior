class Solution {
public:
    vector<int> countBits(int n) {
        int curPower = 1;
        vector<int> result(n+1, 0);

        for (int i = 1; i <= n; ++i) {
            // if we've reached the next power of 2, update the current power
            curPower = curPower * 2 == i ? i : curPower;
            
            result[i] = 1 + result[i-curPower];   
        }
        
        return result;
    }
};
