/* Simple answer that beats 98.33% on runtime and 89.63% on memory

This solution relies on implementing a custom hash function that returns the same number if and only if a word is an anagram. The steps are as follows:

1. Generate a hash code by mapping each character in a word to a prime number and multiplying them all together.
2. Insert the word into the map bucket specified by the hash code.
3. Once all the words are sorted in this way, iterate through the map and append all the vectors into the result vector.

*/
class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        int primes[] = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47, 53, 59, 61, 67, 71, 73, 79, 83, 89, 97, 101};

        map<double, vector<string> > groups;
        
        for (auto str: strs) {
            double hashCode = 1;
            for (auto c = str.begin(); c != str.end(); ++c) hashCode *= primes[(int)*c - (int)'a'];
            groups[hashCode].push_back(str);
        }
        
        vector<vector<string>> result;
        for (const auto& i : groups) {
            result.push_back(i.second);
        }
        
        return result;
    }
};