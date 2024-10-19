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
public:
    int rangeSumBST(TreeNode* root, int lo, int hi) {
        if (!root) return 0;

        int sum = 0;
        if (root->val < hi) sum += rangeSumBST(root->right, lo, hi);
        if (root->val > lo) sum += rangeSumBST(root->left,  lo, hi);

        if (root->val >= lo && root->val <= hi) 
            sum += root->val;

        return sum;
    }
};
