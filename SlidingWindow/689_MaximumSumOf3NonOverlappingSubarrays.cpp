class Solution {
public:
    vector<int> maxSumOfThreeSubarrays(vector<int>& nums, int k) {
        int bestSingleStart = 0;
        vector<int> bestDoubleStart = {0, k};
        vector<int> bestTripleStart = {0, k, 2*k};

        int curSingleSum = accumulate(nums.begin(),  nums.begin()+k, 0);
        int curDoubleSum = accumulate(nums.begin()+k, nums.begin()+(2*k), 0);
        int curTripleSum = accumulate(nums.begin()+(2*k), nums.begin()+(3*k), 0);

        int bestSingleSum = curSingleSum;
        int bestDoubleSum = curSingleSum + curDoubleSum;
        int bestTripleSum = curSingleSum + curDoubleSum + curTripleSum;

        int singleStart = 1, doubleStart = k+1, tripleStart = (2*k)+1;

        while (tripleStart+k <= nums.size()) {
            curSingleSum += nums[singleStart+k-1] - nums[singleStart-1];
            curDoubleSum += nums[doubleStart+k-1] - nums[doubleStart-1];
            curTripleSum += nums[tripleStart+k-1] - nums[tripleStart-1];

            if (curSingleSum > bestSingleSum) {
                bestSingleSum = curSingleSum;
                bestSingleStart = singleStart;
            }

            if (curDoubleSum + bestSingleSum > bestDoubleSum) {
                bestDoubleSum = curDoubleSum + bestSingleSum;
                bestDoubleStart[0] = bestSingleStart;
                bestDoubleStart[1] = doubleStart;
            }

            if (curTripleSum + bestDoubleSum > bestTripleSum) {
                bestTripleSum = curTripleSum + bestDoubleSum;
                bestTripleStart[0] = bestDoubleStart[0];
                bestTripleStart[1] = bestDoubleStart[1];
                bestTripleStart[2] = tripleStart;
            }

            ++singleStart;
            ++doubleStart;
            ++tripleStart;
        }

        return bestTripleStart;
    }
};
