//You are given an array of non-overlapping intervals intervals where intervals[i] = [start_i, end_i] represents the start and the end time of the ith interval. intervals is initially sorted in ascending order by start_i.
//You are given another interval newInterval = [start, end].
//Insert newInterval into intervals such that intervals is still sorted in ascending order by start_i and also intervals still does not have any overlapping intervals. You may merge the overlapping intervals if needed.
//Return intervals after adding newInterval.
//Note: Intervals are non-overlapping if they have no common point. For example, [1,2] and [3,4] are non-overlapping, but [1,2] and [2,3] are overlapping.

class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        vector<vector<int>> result;

        for (int i = 0; i < intervals.size(); ++i) {
            // if the new interval is before the current existing one
            if (newInterval[1] < intervals[i][0]) {
                result.push_back(newInterval);
                result.insert(result.end(), intervals.begin()+i, intervals.end());
                return result;
            }

            // if the new interval is after the current existing one 
            else if (newInterval[0] > intervals[i][1]) {
                result.push_back(intervals[i]);
            }

            // the new interval is overlapping
            else {
                newInterval[0] = min(newInterval[0], intervals[i][0]);
                newInterval[1] = max(newInterval[1], intervals[i][1]);
            }
        }

        result.push_back(newInterval);
        return result;
    }
};
