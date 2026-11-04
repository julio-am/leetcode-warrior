class Solution {
public:
    int trap(vector<int>& height) {
        int l = 0, r = height.size()-1, result = 0;
        int maxL = height[l];
        int maxR = height[r];

        while (l < r) {
            if (maxL < maxR) {
                ++l;
                maxL = max(maxL, height[l]);
                result += maxL - height[l];

            }
            else {
                --r;
                maxR = max(maxR, height[r]);
                result += maxR - height[r];
            }
        }

        return result;

    }
};
