class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        if (numRows == 0) return {};

        vector<vector<int>> result = {{1}};

        for (int i = 1; i < numRows; ++i) {
            vector<int> parent = result[i-1];
            parent.insert(parent.begin(), 0);
            parent.push_back(0);

            int left = 0;
            int right = 1;
            vector<int> newRow;
          
            while (right < parent.size()) {
                newRow.push_back(parent[left] + parent[right]);
                ++left;
                ++right;
            }

            result.push_back(newRow);
        }

        return result;
    }
};
