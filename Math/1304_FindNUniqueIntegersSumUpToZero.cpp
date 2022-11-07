//Given an integer n, return any array containing n unique integers such that they add up to 0.

class Solution {
public:
    vector<int> sumZero(int n) {
        vector<int> result;
        int sum = 0;
        for (int i = 1; i < n; ++i) {
            result.push_back(i);
            sum+=i;
        }
        result.push_back(sum*-1);
        return result;
    }
};