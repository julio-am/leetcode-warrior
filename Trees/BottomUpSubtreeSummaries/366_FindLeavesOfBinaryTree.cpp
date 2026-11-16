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

map<int, vector<int>> mp;

int getHeight(TreeNode* root) {
    if (!root) return -1;

    // calculate the heights of the left and right children
    int lh = getHeight(root->left);
    int rh = getHeight(root->right);

    int curHeight = max(lh, rh) + 1;

    mp[curHeight].push_back(root->val);
    return curHeight;
}


public:
    vector<vector<int>> findLeaves(TreeNode* root) {
        getHeight(root);

        vector<vector<int>> result;
        for (auto it : mp) result.push_back(it.second);

        return result;
    }
};
