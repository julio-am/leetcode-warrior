//Perform the following shift operations on a string:

//Right shift: Replace every letter with the successive letter of the English alphabet, where 'z' is replaced by 'a'. For example, "abc" can be right-shifted to "bcd" or "xyz" can be right-shifted to "yza".
//Left shift: Replace every letter with the preceding letter of the English alphabet, where 'a' is replaced by 'z'. For example, "bcd" can be left-shifted to "abc" or "yza" can be left-shifted to "xyz".
//We can keep shifting the string in both directions to form an endless shifting sequence.

//For example, shift "abc" to form the sequence: ... <-> "abc" <-> "bcd" <-> ... <-> "xyz" <-> "yza" <-> .... <-> "zab" <-> "abc" <-> ...
//You are given an array of strings strings, group together all strings[i] that belong to the same shifting sequence. You may return the answer in any order.

class Solution {
public:
    vector<vector<string>> groupStrings(vector<string>& strings) {
        unordered_map<string, vector<string>> groups;

        for (auto str : strings) {
            string hashCode = "#";

            for (int i = 1; i < str.length(); ++i) {
                int shift = (int)str[i] - (int)str[0];
                if (shift < 0) {
                    shift += 26;
                }

                hashCode.append(to_string(shift));
                hashCode.append("#");
            }

            groups[hashCode].push_back(str);
        }

        vector<vector<string> > result;
        for (auto group : groups) {
            result.push_back(group.second);
        }

        return result;
    }
};
