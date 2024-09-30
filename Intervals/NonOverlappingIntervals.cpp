class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end());

        int count = 0;
        int prevEnd = intervals[0][1];


// for interval problems that involve prevEnd, index starting from 1
        for (int i = 1; i<intervals.size(); ++i) {
            if (intervals[i][0] >= prevEnd) {
                // keep prevEnd
                prevEnd = intervals[i][1];
            }

            else {
                ++count;
                // Keep PrevEnd of the interval that ends first
                prevEnd = min(prevEnd, intervals[i][1]);
            }
            
        }

        return count;
    }
};
