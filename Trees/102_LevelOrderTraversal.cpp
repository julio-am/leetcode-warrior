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
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> result;
        queue<TreeNode*> toVisit;
        toVisit.push(root);
        
        while (!toVisit.empty()) {
            int levelSize = toVisit.size();
            vector<int> list;
            for (int i = 0; i<levelSize; ++i) {
                TreeNode* current = toVisit.front();
                toVisit.pop();
                if (current) {
                    toVisit.push(current->left);
                    toVisit.push(current->right);
                    list.push_back(current->val);
                }
            }
            if (list.size()) result.push_back(list);
        }
        return result;
    }
};