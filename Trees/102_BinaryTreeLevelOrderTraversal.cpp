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

    vector<vector<int>> levelOrder(TreeNode* root) {
        if (!root) return {}
        vector<vector<int>> result;

        queue<TreeNode*> toVisit;
        toVisit.push(root);

        while (!toVisit.empty()) {
            vector<int> current;
            int len = toVisit.size();

            for (int i = 0; i<len; ++i) {
                current.push_back(toVisit.front()->val);

                if (toVisit.front()->left)  toVisit.push(toVisit.front()->left);
                if (toVisit.front()->right) toVisit.push(toVisit.front()->right);
                toVisit.pop();
            }

            result.push_back(current);
        }

        return result;
    }
    






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
