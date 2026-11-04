class Solution {
public:
    int minNumberOperations(vector<int>& target) {
        int result = target[0];
        int current = target[0];

        // As we iterate across the array, add the number of operations 
        // needed to get to the current height of the stack. 
        for (int i = 1; i<target.size(); ++i) {
            result += max(0, target[i] - current);
            current = target[i];
        }

        return result;
    }
};
