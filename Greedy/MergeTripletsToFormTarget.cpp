//You are given a 2D array of integers triplets, where triplets[i] = [ai, bi, ci] represents the ith triplet. You are also given an array of integers target = [x, y, z] which is the triplet we want to obtain.

///To obtain target, you may apply the following operation on triplets zero or more times:

//Choose two different triplets triplets[i] and triplets[j] and update triplets[j] to become [max(ai, aj), max(bi, bj), max(ci, cj)].
//* E.g. if triplets[i] = [1, 3, 1] and triplets[j] = [2, 1, 2], triplets[j] will be updated to [max(1, 2), max(3, 1), max(1, 2)] = [2, 3, 2].

//Return true if it is possible to obtain target as an element of triplets, or false otherwise.

class Solution {
public:
    bool mergeTriplets(vector<vector<int>>& triplets, vector<int>& target) {
        unordered_set<int> found;

        for (auto triplet : triplets) {
            if (triplet[0] > target[0] ||
                triplet[1] > target[1] ||
                triplet[2] > target[2]) {
                    continue;
            }

            for (int i = 0; i < target.size(); ++i) {
                if (triplet[i] == target[i]) {
                    found.insert(i);
                }
            }
        }

        // can also check if count.size() is 3 but this is more clear imo
        return (found.count(0) && found.count(1) && found.count(2));
    }
};
