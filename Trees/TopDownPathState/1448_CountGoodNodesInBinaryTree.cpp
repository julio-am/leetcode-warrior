//Within a binary tree, a node x is considered good if the path from the root of the tree to the node x contains no nodes with a value greater than the value of node x
//Given the root of a binary tree root, return the number of good nodes within the tree.

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */

class Solution {

    int result = 0;

    void dfs(TreeNode* root, int maxSeen) {
        if (!root) return;

        if (root->val >= maxSeen) ++result;
        maxSeen = max(root->val, maxSeen);
        
        dfs(root->left, maxSeen);
        dfs(root->right, maxSeen);
    }

public:
    int goodNodes(TreeNode* root) {
        dfs(root, INT_MIN);
        return result;
    }
};
