//Given the root of a binary tree, return the vertical order traversal of its nodes' values. (i.e., from top to bottom, column by column).
//If two nodes are in the same row and column, the order should be from left to right.

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
    vector<vector<int>> verticalOrder(TreeNode* root) {
        map<int, vector<int>> cols;
        
        queue<pair<TreeNode*, int>> q;
        q.push({root, 0});

        while (!q.empty()) {
            auto curr = q.front();
            q.pop();

            if (curr.first == NULL) {continue;}

            cols[curr.second].push_back(curr.first->val);
            q.push({curr.first->left, curr.second-1});
            q.push({curr.first->right, curr.second+1});
        }

        vector<vector<int>> result;
        for (auto pair : cols) {
            result.push_back(pair.second);
        }

        return result;
    }

//dfs wont work because the cols need to be printed out in order from top to bottom
//private:
    //void dfs(TreeNode* root, int col, map<int, vector<int>>& cols) {
    //    if (root == NULL) return;

    //    cols[col].push_back(root->val);

    //    dfs(root->left, col-1, cols);
    //    dfs(root->right, col+1, cols);
    //}
};
