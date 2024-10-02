class Solution {

private:
    vector<vector<int>> weights;
    int curSum;

    int getRandomNumber(int min, int max) {
        std::random_device rd;  // Initialize random device
        std::mt19937 gen(rd()); // Seed the random number generator
        std::uniform_int_distribution<> distr(min, max); // Define the range 
        return distr(gen); // Return a random number in the range
    }

public:
    Solution(vector<int>& w) {
        curSum = 0;

        for (int i = 0; i < w.size(); ++i) {
            weights.push_back({curSum+1, curSum + w[i]});
            curSum += w[i];
        }
    }
    
    int pickIndex() {
        int rand = getRandomNumber(1, curSum);

        // binary search to find solution
        int left = 0;
        int right = weights.size()-1;

        while (left <= right) {
            int mid = (left + right) / 2;
            vector<int> found = weights[mid];

            // if result 
            if (found[0] <= rand && found[1] >= rand) return mid;

            // if found is too big
            if (found[0] > rand) right = mid-1;

            // if found is too small 
            else if (found[1] < rand) left = mid+1;
        }

        return -1;
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(w);
 * int param_1 = obj->pickIndex();
 */
