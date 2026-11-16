class Solution {
public:
    vector<int> findBuildings(vector<int>& heights) {
        // go backwards
        vector<int> result;
        int maxHeight = INT_MIN;

        for (int i = heights.size()-1; i >= 0; --i) {
            if (heights[i] > maxHeight) {
                result.push_back(i);
                maxHeight = heights[i];
            }
        }

        // reverse to get shortest building first
        reverse(result.begin(), result.end());
        return result;
    }
};
