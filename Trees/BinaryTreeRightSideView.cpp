//You are given the root of a binary tree. Return only the values of the nodes that are visible from the right side of the tree, ordered from top to bottom.

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
    vector<int> rightSideView(TreeNode* root) {
       if (!root) return {};
       
       vector<int> result;
       queue<TreeNode*> toVisit;
       toVisit.push(root);

        while (!toVisit.empty()) {
            int levelSize = toVisit.size();
            for (int i = 0; i<levelSize; ++i) {
                TreeNode* node = toVisit.front();
                toVisit.pop();
                if (node->left) toVisit.push(node->left);
                if (node->right) toVisit.push(node->right);
                if (i == levelSize-1) result.push_back(node->val);
            }
        }

        return result;
    }
};
