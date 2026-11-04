class Solution {
public:
    vector<vector<int>> intervalIntersection(vector<vector<int>>& a, vector<vector<int>>& b) {
        vector<vector<int>> result;

        int i = 0, j = 0;
        while (i < a.size() && j < b.size()) {
            // Intersection is defined as the numbers where both
            // A and B have values.
            //If the biggest startpoint is less than the smallest endpoint,
            // Add that new interval to our results,
            // then get rid of the existing interval that ends earlist.
            int low = max(a[i][0], b[j][0]);
            int high = min(a[i][1], b[j][1]);

            if (low <= high) {
                result.push_back({low, high});
            }

            // Remove the interval that ends first
            if (a[i][1] < b[j][1]) {
                ++i;
            }
            else {
                ++j;
            }
        }

        return result;
    }
};
