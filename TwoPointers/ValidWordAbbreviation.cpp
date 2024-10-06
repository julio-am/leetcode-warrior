//Given a string word and an abbreviation abbr, return whether the string matches the given abbreviation.
//A string can be abbreviated by replacing any number of non-adjacent, non-empty substrings with their lengths. The lengths should not have leading zeros.


class Solution {
public:
    bool validWordAbbreviation(string word, string abbr) {
        int wordPos = 0, abbrPos = 0;

        while (wordPos < word.size() && abbrPos < abbr.size()) {
            // if we found numbers
            if (isdigit(abbr[abbrPos])) {
                if (abbr[abbrPos] == '0') return false;

                int numToSkip = 0;
                while (abbrPos < abbr.size() && isdigit(abbr[abbrPos])) {
                    numToSkip = 10 * numToSkip + (abbr[abbrPos] - '0'); 
                    ++abbrPos;
                }

                wordPos += numToSkip;
            }

            // if we found letters but they're not equal
            else if (word[wordPos++] != abbr[abbrPos++]) return false;
        }

        // ensure we have reached the end of both the word and the abbreviation
        return (wordPos == word.size() && abbrPos == abbr.size());
    }
};
