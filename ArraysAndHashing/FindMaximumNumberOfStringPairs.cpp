//You are given a 0-indexed array words consisting of distinct strings.

//The string words[i] can be paired with the string words[j] if:

//The string words[i] is equal to the reversed string of words[j].
//0 <= i < j < words.length.
//Return the maximum number of pairs that can be formed from the array words.

//Note that each string can belong in at most one pair.

class Solution {
public:
    int maximumNumberOfStringPairs(vector<string>& words) {
        int result = 0;
        unordered_set<string> seen;

        for (auto w : words) {
            string reverse(w.rbegin(), w.rend());
            if (seen.count(reverse)) {
                ++result;
                continue;
            }

            seen.insert(w);
        }

        return result;
    }
};