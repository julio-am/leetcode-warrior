class Solution {
public:
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        queue<int> toVisit;
        vector<bool> seen(rooms.size(), false);
        int seenCount = 0;
        seen[0] = true;
        ++seenCount;
        toVisit.push(0);

        while (!toVisit.empty()) {
            int cur = toVisit.front();
            toVisit.pop();
            for (auto next : rooms[cur]) {
                if (!seen[next]) {
                    toVisit.push(next);
                    seen[next] = true;
                    seenCount++;
                }
            }
        }

        return seenCount == rooms.size();
    }
};
