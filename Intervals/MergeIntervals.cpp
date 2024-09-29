class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end());

        vector<vector<int>> result;
        for (auto interval : intervals) {

            // if there is no previous interval, or if the last interval ends before the current one starts,
            // insert the current interval.
            if (result.empty() || result.back()[1] < interval[0])
                result.push_back(interval);

            // if there is a conflict of intervals, update the ending of the existing interval to be the 
            // latest we've seen so far.
            else 
                result.back()[1] = max(result.back()[1], interval[1]);
        }

        return result;
    }
};
