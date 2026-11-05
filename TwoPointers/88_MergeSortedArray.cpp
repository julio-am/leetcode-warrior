// Alternative implementations; submit one at a time.

// ============================================================================
// Approach 1 — original: TwoPointers/88_MergeSortedArray.cpp
// ============================================================================
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


// ============================================================================
// Approach 2 — original: ArraysAndHashing/MergeSortedArray.cpp
// ============================================================================
class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int p1 = m-1;
        int p2 = n-1;

        // start from back of longer list 
        for (int i = m+n - 1; i >= 0; --i){
            if (p2 < 0) break;

            if (p1 >= 0 && nums1[p1] > nums2[p2]) {
                nums1[i] = nums1[p1];
                --p1;
            }

            else {
                (nums1[i]) = nums2[p2];
                --p2;
            }
        }
    }
};

