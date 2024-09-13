// Given the roots of two binary trees root and subRoot, return true if there is a subtree of root with the same structure and node values of subRoot and false otherwise.
// A subtree of a binary tree tree is a tree that consists of a node in tree and all of this node's descendants. The tree tree could also be considered as a subtree of itself.


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

    bool isSameTree(TreeNode* root, TreeNode* subRoot){
        if (!root && !subRoot) return true;

        if (root && subRoot && root->val == subRoot->val) 
            return isSameTree(root->left, subRoot->left)
                    && isSameTree(root->right, subRoot->right);

        return false;
    }

    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        // base cases
        if (!subRoot) return true;
        if (!root) return false;

        if (root->val == subRoot->val) return isSameTree(root, subRoot);

        return isSubtree(root->left, subRoot) || isSubtree(root->right, subRoot);
    }
};
