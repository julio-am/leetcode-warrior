//You are given a directed graph with n nodes labeled from 0 to n - 1, where each node has exactly one outgoing edge.
//The graph is represented by a given 0-indexed integer array edges of length n, where edges[i] indicates that there is a directed edge from node i to node edges[i].
//The edge score of a node i is defined as the sum of the labels of all the nodes that have an edge pointing to i.
//Return the node with the highest edge score. If multiple nodes have the same edge score, return the node with the smallest index.

class Solution {
public:
    int edgeScore(vector<int>& edges) {
        vector<long> scoreCount(edges.size());

        for (int i = 0; i < edges.size(); ++i) {
            scoreCount[edges[i]] += i;
        }

        long result = 0;
        long maxScore = INT_MIN;
        for (int i = 0; i<scoreCount.size(); ++i) {
            if (scoreCount[i] > maxScore) {
                result = i;
                maxScore = scoreCount[i];
            }
        }   
        return result;
    }
};
