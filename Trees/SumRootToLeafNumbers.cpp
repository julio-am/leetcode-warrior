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

    void dfs(TreeNode* root, int n, int& result) {
        if (root) {
            n = (10*n) + root->val;
            
            // if leaf
            if (!root->left && !root->right) result += n;    
            
            // do left and right
            dfs(root->left, n, result);
            dfs(root->right, n, result);
        }
    }

public:
    int sumNumbers(TreeNode* root) {
        int result = 0;
        dfs(root, 0, result);
        
        return result;
    }
};
