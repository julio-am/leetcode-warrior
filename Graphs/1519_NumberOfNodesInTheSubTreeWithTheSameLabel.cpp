class Solution {

vector<int> dfs(int node,
                int parent,
                vector<vector<int>>& adj, 
                vector<int>& result,
                string labels) {

    vector<int> labelCounts(26, 0);
    labelCounts[labels[node] - 'a'] = 1;

    for (auto next : adj[node]) {
        if (next == parent) continue;

        vector<int> childCounts = dfs(next, node, adj, result, labels);

        for (int i = 0; i < childCounts.size(); ++i)
            labelCounts[i] += childCounts[i];
    }

    result[node] = labelCounts[labels[node] - 'a'];

    return labelCounts;
}


public:
    vector<int> countSubTrees(int n, vector<vector<int>>& edges, string labels) {
        // create adjacency list for edges
        vector<vector<int>> adj(n);
        for (auto edge : edges) {
            adj[edge[0]].push_back(edge[1]);
            adj[edge[1]].push_back(edge[0]);
        }
        
        vector<int> result(n);
        dfs(0, -1, adj, result, labels);

        return result;
    }
};
