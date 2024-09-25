class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        vector<vector<int>> result;
    
        sort(intervals.begin(), intervals.end());

        int previousStart = intervals[0][0];
        int previousEnd = intervals[0][1];
        for (int i = 0; i < intervals.size(); ++i) {
            //if the previous interval is before the next one, insert the previous interval;
            if (previousEnd < intervals[i][0]) {
                result.push_back({previousStart, previousEnd});
                previousStart = intervals[i][0];
                previousEnd = intervals[i][1];
                continue;
            }

            // if the previous interval ends after the current one starts 
            else if (previousEnd >= intervals[i][0]) {
                previousEnd = max(previousEnd, intervals[i][1]);
                continue;
            }
        }

        // insert the last interval
        result.push_back({previousStart, previousEnd});
        return result;
    }
};
