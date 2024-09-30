/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
private:
    TreeNode* result;

    // recurse through the tree and set the result to be the first node sych that 
    // either the left subtree, the right subtree, or itself contain both p and q.
    bool recurseTree(TreeNode* root, TreeNode* p, TreeNode* q) {
        if (!root) return false;

        bool curr = root == p || root == q;
        bool left = recurseTree(root->left, p, q);
        bool right = recurseTree(root->right, p, q);

        if (left + right + curr >= 2)  result = root;

        return left || right || curr;
    }

public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        recurseTree(root, p, q);
        return result;
    }
};
