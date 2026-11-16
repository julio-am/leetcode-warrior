class Solution {
public:
    bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {
        
        // create graph
        unordered_map<int, vector<int>> graph;
        for (auto& edge : edges) {
            int src = edge[0], dest = edge[1];
            graph[src].push_back(dest);
            graph[dest].push_back(src);
        }


        queue<int> q;
        unordered_set<int> seen;

        q.push(source);
        seen.insert(source);

        while (!q.empty()) {
            if (q.front() == destination) return true;

            int cur = q.front();
            q.pop();

            for (auto next : graph[cur]) {
                if (!seen.contains(next))
                q.push(next);
                seen.insert(next);
            }
        }

        return false;
    }
};
