// 1557: minimum vertices to reach all nodes

class Solution {
public:

    // Iterate through all the nodes, and add each node that doesn't 
    // have any incoming edges to our result.
    vector<int> findSmallestSetOfVertices(int n, vector<vector<int>>& edges) {
        std::map<int, int> visitCount;
        visitCount.get_allocator().reserve(sizeof(int) * n);
        
        vector<int> result;
        
        for (vector<int> edge : edges)
            visitCount[edge[1]] += 1;
        
        for (int i = 0; i<n; ++i)
            if (visitCount[i] == 0)
                result.push_back(i);

        return result;
    }
};