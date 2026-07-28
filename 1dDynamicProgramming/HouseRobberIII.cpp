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
private:

    pair<int,int> helper(TreeNode* root) {
        if (!root) return {0,0};

        pair<int,int> l = helper(root->left);
        pair<int,int> r = helper(root->right);

        // if we rob current we can't rob children
        int rob = root->val + l.second + r.second; 

        // if we don't rob current we can choose to rob children
        int notRob = max(l.first, l.second) + max(r.first, r.second);

        return {rob, notRob};
    }

public:
    int rob(TreeNode* root) {
        pair<int,int> results = helper(root);
        return max(results.first, results.second);
    }
};
