class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        // leetcode please index from 0
        --m;--n;
        int insert = nums1.size()-1;

        while (m >= 0 && n >= 0) {
            if (nums1[m] > nums2[n]) {
                nums1[insert] = nums1[m];
                --m;
            }
            else {
                nums1[insert] = nums2[n];
                --n;
            }
            --insert;
        }

        // fill in remaining elements from nums2
        for (n; n >= 0; --n, --insert) {
            nums1[insert] = nums2[n];
        }
    }
};
