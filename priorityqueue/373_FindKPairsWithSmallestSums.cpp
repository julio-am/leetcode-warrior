class Solution {
public:
    vector<vector<int>> kSmallestPairs(vector<int>& nums1, vector<int>& nums2, int k) {
        int n = nums1.size();
        int m = nums2.size();

        vector<vector<int>> result;
        set<pair<int,int>> visited; // keeps track of pairs we've already added to queue

        priority_queue<pair<int, pair<int,int>>,
                       vector<pair<int, pair<int, int>>>,
                       greater<pair<int, pair<int, int>>>> minHeap; // running queue containing next two pairs to compare

        minHeap.push({nums1[0] + nums2[0], {0, 0}});
        visited.insert({0,0});

        while (k-- && !minHeap.empty()) {
            auto top = minHeap.top();
            minHeap.pop();
            int i = top.second.first;
            int j = top.second.second;

            result.push_back({nums1[i], nums2[j]});

            if (i+1 < n && !visited.contains({i+1, j})) {
                minHeap.push({nums1[i+1]+nums2[j], {i+1, j}});
                visited.insert({i+1, j});
            }

            if (j+1 < m && !visited.contains({i, j+1})) {
                minHeap.push({nums1[i]+nums2[j+1], {i, j+1}});
                visited.insert({i, j+1});
            }
        }

        return result;
    }
};
