class Solution {
public:
    int shipWithinDays(vector<int>& weights, int maxDays) {
        int l = *max_element(weights.begin(), weights.end());
        int r = accumulate(weights.begin(), weights.end(),0);
        int result = r;


        // This is a "find minimum satisfying condition" problem.
        // When the capacity works, you should search left (r = mid - 1) 
        // to find smaller valid capacities.
        while (l <= r) {
            int capacity = l + (r-l)/2;
            long long daysSpent = timeSpent(weights, capacity);

            // if shipped too fast
            if (daysSpent <= maxDays) {
                result = capacity;
                r = capacity-1;
            }

            else l = capacity+1;
        }

        return result;
    }

    long long timeSpent(vector<int>& weights, double capacity) {
        long long result = 1;
        long long current = 0;
        for (auto weight : weights) {
            current += weight;
            if (current > capacity) {
                ++result;
                current = weight;
            }
        }
        return result;
    }
};
