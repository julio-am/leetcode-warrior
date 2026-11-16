class Solution {

private: 
long long fuel = 0;

int dfs(vector<vector<int>>& adj, int node, int parent, int seats) {
    int representatives = 1;

    for (auto next : adj[node])
        if (next != parent)
            representatives += dfs(adj, next, node, seats);

    if (node != 0)
        fuel += ceil(1.0 * representatives / seats);

    return representatives;
}

public:
    long long minimumFuelCost(vector<vector<int>>& roads, int seats) {
        // create adjacency list
        vector<vector<int>> adj(roads.size()+1);
        for (auto road : roads) {
            adj[road[0]].push_back(road[1]);
            adj[road[1]].push_back(road[0]);
        }

        dfs(adj, 0, -1, seats);
        return fuel;
    }
};
