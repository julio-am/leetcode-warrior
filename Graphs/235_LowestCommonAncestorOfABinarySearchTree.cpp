// Alternative implementations; submit one at a time.

// ============================================================================
// Approach 1 — original: Graphs/LowestCommonAncestorOfABinarySearchTree.cpp
// ============================================================================
//Given a binary search tree (BST), find the lowest common ancestor (LCA) node of two given nodes in the BST.

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
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) { 
        while (root != NULL) {
            if (p->val > root->val && q->val > root->val)
                root = root->right;

            else if (p->val < root->val && q->val < root->val)
                root = root->left;

            else
                return root;
        }

        return root;
    }
};


// ============================================================================
// Approach 2 — original: Trees/xx_LowestCommonAncestorInBinarySearchTree.cpp
// ============================================================================
//Given a binary search tree (BST) where all node values are unique, and two nodes from the tree p and q, return the lowest common ancestor (LCA) of the two nodes.
//The lowest common ancestor between two nodes p and q is the lowest node in a tree T such that both p and q as descendants. The ancestor is allowed to be a descendant of itself.

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
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if (!root)
            return NULL;
        
        if (p->val == root->val && q->val == root->val)
        return root;

        if ((p->val > root->val) != (q->val > root->val))
            return root;
        
        if (p->val > root->val && q->val > root->val)
            return lowestCommonAncestor(root->right, p, q);

        if (p->val < root->val && q->val < root->val)
            return lowestCommonAncestor(root->left, p, q);
    }
};

