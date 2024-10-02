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
    int result;

    void dfs(TreeNode* root, int low, int high) {
        if (!root) return;
        int cur = root->val;

        if (cur >= low && cur <= high)
            result += cur;

        if (cur > low) 
            dfs(root->left, low, high);

        if (cur < high)
            dfs(root->right, low, high);
    }

public:
    int rangeSumBST(TreeNode* root, int low, int high) {
        dfs(root, low, high);
        return result;
    }
};
