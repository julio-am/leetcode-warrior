// Given a weighted, directed graph, and a starting vertex,
// return the shortest distance from the starting vertex to every vertex in the graph.

// Input:
// n - the number of vertices in the graph, where (2 <= n <= 100). Each vertex is labeled from 0 to n - 1.
// edges - a list of tuples, each representing a directed edge in the form (src, dest, weight).
// src - the source vertex from which to start the algorithm.


class Solution {
public:
    unordered_map<int, int> shortestPath(int n, vector<vector<int>>& edges, int src) {
        //create adjacency list from edges
        // vector< pair(weight, edge) >
        unordered_map<int, vector<pair<int,int>>> adj;
        for(auto edge : edges) 
            adj[edge[0]].push_back({edge[2], edge[1]});

        // <node, distance of shortest path>
        unordered_map<int, int> result;

        // Syntax: priority_queue<Type, Container, Comparator>
        priority_queue<pair<int,int>, 
                       vector<pair<int,int>>,
                       greater<pair<int,int>>> minHeap;
        minHeap.push({0, src});

        while (!minHeap.empty()) {
            int weight = minHeap.top().first;
            int node = minHeap.top().second;
            minHeap.pop();

            // if we already processed the current node, skip
            if (result.contains(node)) continue;

            result[node] = weight;
            
            for (auto next : adj[node]) {
                int nextWeight = next.first;
                int nextNode = next.second;

                // if next node not already visited, add it to the heap to visit
                if (!result.contains(nextNode))
                    minHeap.push({weight+nextWeight, nextNode});
            } 
        }

        //fill in distance for nodes that never got visited
        for (int i = 0; i < n; ++i)
            if (!result.contains(i)) result[i] = -1;

       return result;
    }
};
