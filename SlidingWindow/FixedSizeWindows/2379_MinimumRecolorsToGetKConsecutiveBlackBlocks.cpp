class Solution {
public:
    int minimumRecolors(string blocks, int k) {
        int curB = 0;
        for (int i = 0; i < k; ++i) {
            if (blocks[i] == 'B') ++curB;
        }

        int maxB = curB;
        for (int i = k; i < blocks.size(); ++i) {
            if (blocks[i] == 'B') ++curB;
            if (blocks[i-k] == 'B') --curB;

            maxB = max(maxB, curB);
        }

        return k-maxB;
    }
};
