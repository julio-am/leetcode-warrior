//Given a node in a connected undirected graph, return a deep copy of the graph.
//Each node in the graph contains an integer value and a list of its neighbors.

/*
class Node {
    public int val;
    public List<Node> neighbors;
}
*/

//The graph is shown in the test cases as an adjacency list. An adjacency list is a mapping of nodes to lists, used to represent a finite graph. Each list describes the set of neighbors of a node in the graph.
//For simplicity, nodes values are numbered from 1 to n, where n is the total number of nodes in the graph. The index of each node within the adjacency list is the same as the node's value (1-indexed).
//The input node will always be the first node in the graph and have 1 as the value.

/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class Solution {

    Node* dfs(Node* node, unordered_map<Node*, Node*>& oldToNew) {
        // if node doesn't exist return null
        if (!node) return NULL;

        // if the node has been copied already, return the copy
        if (oldToNew.count(node)) return oldToNew[node];

        // make a new copy of the node and put it in hashmap
        Node* copy = new Node(node->val);
        oldToNew[node] = copy;

        // recursively copy each neighbor and add it to the list of the new node's neighbors
        for (auto neighbor : node->neighbors) {
            copy->neighbors.push_back(dfs(neighbor, oldToNew));
        }

        // return the copied node
        return copy;
    }

public:
    Node* cloneGraph(Node* node) {
        unordered_map<Node*, Node*> oldToNew;
        return dfs(node, oldToNew);
    }
};
