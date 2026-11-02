class Solution {

private:
int goodCount = 0;

int dfs(vector<vector<int>>& edges, int node, int parent) {
    int subtreeSize = 1;
    int firstChildSize = -1;
    bool good = true;

    for (auto next : edges[node]) {
        if (next == parent) continue;
        
        int childSize = dfs(edges, next, node);

        if (firstChildSize == -1) 
            firstChildSize = childSize;

        else if (childSize != firstChildSize)
            good = false;

        subtreeSize += childSize;
    
    }

    if (good) ++goodCount;
    return subtreeSize;
}

public:
    int countGoodNodes(vector<vector<int>>& edges) {
        vector<vector<int>> adj(edges.size()+1);

        for (auto e : edges) {
            adj[e[0]].push_back(e[1]);
            adj[e[1]].push_back(e[0]);
        }

        dfs(adj, 0, -1);
        return goodCount;
    }
};
