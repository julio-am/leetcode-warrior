class Solution {
vector<vector<int>> result;

void helper(int n, int k, int i, vector<int>& cur) {
    if (cur.size() == k) {
        result.push_back(cur);
        return;
    }

    if (i > n) return;

    cur.push_back(i);
    helper(n, k, i+1, cur);

    cur.pop_back();
    helper(n, k, i+1, cur);
}

public:
    vector<vector<int>> combine(int n, int k) {
        vector<int> cur = {};
        helper(n, k, 1, cur);
        return result;
    }
};
