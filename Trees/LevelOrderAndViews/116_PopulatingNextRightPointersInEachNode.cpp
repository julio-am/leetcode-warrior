/*
// Definition for a Node.
class Node {
You are given a perfect binary tree where all leaves are on the same level, and every parent has two children. The binary tree has the following definition:

Populate each next pointer to point to its next right node. If there is no next right node, the next pointer should be set to NULL.

Initially, all next pointers are set to NULL.

public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
*/

class Solution {
public:
    Node* connect(Node* root) {
        if (!root) return root;

        queue<Node*> q;
        q.push(root);

        while (!q.empty()) {
            int levelSize = q.size();

            for (int i = 0; i<levelSize; ++i) {
                Node* curNode = q.front();
                q.pop();

                if (i != levelSize-1) {
                    curNode->next = q.front();
                }

                if (curNode->left) q.push(curNode->left);
                if (curNode->right) q.push(curNode->right);
            }
        }

        return root;
    }
};
