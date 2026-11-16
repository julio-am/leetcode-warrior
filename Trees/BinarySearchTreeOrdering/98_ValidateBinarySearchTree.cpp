//98. Validate Binary Search Tree

class Solution {

private:

    struct Node {
        int val;
        Node* left;
        Node* right;

        Node() : val(0), left(nullptr), right(nullptr) {}
        Node(int val) : val(val), left(nullptr), right(nullptr) {}
        Node(int val, Node* left, Node* right) : val(val), left(left), right(right) {}
    };

public:
    bool isValidBST (Node* root)
    {
        return helper (root, LONG_MIN, LONG_MAX);
    }
    
    bool helper (Node* root, long min, long max)
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