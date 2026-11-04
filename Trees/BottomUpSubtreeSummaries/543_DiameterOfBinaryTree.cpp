//Given the root of a binary tree, return the length of the diameter of the tree.
//The diameter of a binary tree is the length of the longest path between any two nodes in a tree. This path may or may not pass through the root.
//The length of a path between two nodes is represented by the number of edges between them

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

    int result = 0;

    int longestPath(TreeNode* root) {
        if (!root) return 0;

        // Find the longest path to the current node from the left side
        int left = longestPath(root->left);

        // Find the longest path to the current node from the right side
        int right = longestPath(root->right);

        // Set the global diameter to be the maximum between the current diameter,
        // and the distance between the furthest left node and the furthest right node.
        result = max(result, left+right);

        // the distance from the farthest leaf to the node above us is the longest of the left and right branches +1. 
        return max(left, right)+1;
    }

public:
    int diameterOfBinaryTree(TreeNode* root) {
        longestPath(root);
        return result;
    }
};
