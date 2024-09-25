class Solution {
public:
    int minMeetingRooms(vector<vector<int>>& intervals) {
        vector<int> start;
        vector<int> end;
        for (auto i : intervals) {
            start.push_back(i[0]);
            end.push_back(i[1]);
        }

        sort(start.begin(), start.end());
        sort(end.begin(), end.end());

        int s = 0, e = 0, result = 0;

        while (s < start.size()) {
            if (start[s] < end[e]) {
                ++s;
                result = max(result, s-e);
            }

            else {
                ++e;
            }
        }

        return result;
    }
};
