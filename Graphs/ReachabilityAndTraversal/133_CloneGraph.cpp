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
private:

unordered_map<Node*, Node*> mp;

public:
    Node* cloneGraph(Node* node) {
        if (!node) return NULL;

        // if node already copied, return the copy
        if (mp.find(node) != mp.end()) return mp[node];

        // make copy of current node
        Node* copy = new Node(node->val);
        mp[node] = copy;

        // make copies of each neighbor
        for (auto n : node->neighbors)
            copy->neighbors.push_back(cloneGraph(n));

        return copy;
    }
};
