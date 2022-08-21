Trees



class Solution {
public:
    bool isValidBST (TreeNode* root)
    {
        return helper (root, LONG_MIN, LONG_MAX);
    }
    
    bool helper (TreeNode* root, long min, long max)
    {
        if (!root) {
            return true;
        }
        
        if (root->val <= min || root->val >= max) {
            return false;
        }

        return helper (root->left, min, root->val) &&
               helper (root->right, root->val, max);
    }
};