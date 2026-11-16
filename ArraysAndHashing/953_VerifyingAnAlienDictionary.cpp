//In an alien language, surprisingly, they also use English lowercase letters, but possibly in a different order. The order of the alphabet is some permutation of lowercase letters.
//Given a sequence of words written in the alien language, and the order of the alphabet, return true if and only if the given words are sorted lexicographically in this alien language.

class Solution {
public:
    bool isAlienSorted(vector<string>& words, string order) {
        if (words.size() <= 1) return true;

        // Create a map of values corresponding to each char
        unordered_map<char, int> value;
        for (int i = 0; i < order.size(); ++i) {
            value[order[i]] = i;
        }

        // Check if each word rightfully comes after the previous word
        string prevWord = words[0];
        for (int i = 1; i < words.size(); ++i) {
            string curWord = words[i];

            for (int j = 0; j < prevWord.size(); ++j) {

                // If we reached the end of the next word first, return false
                if (j == curWord.size()) return false;

                int prevVal = value[prevWord[j]];
                int curVal = value[curWord[j]];                

                // if previous word is rightfully smaller, move onto next word
                if (prevVal < curVal) break;

                // if prevWord is bigger, return false immediately
                if (curVal < prevVal) return false;
            }

            prevWord = curWord;
        }

        return true;
    }
};
