class Solution {
public:
    int tribonacci(int n) {
        vector<int> trib = {0,1,1};

        if (n < 3) return trib[n];

        for (int i = 3; i <= n; ++i){
            int newTrib = trib[0] + trib[1] + trib[2];
            trib[0] = trib[1];
            trib[1] = trib[2];
            trib[2] = newTrib;
        }

        return trib[2];
    }
};
