class TrieNode {
public:
    TrieNode* children[10]{};
};

class Trie {
  TrieNode* root;

public:
    Trie() : root(new TrieNode()) {}

    void insert (int n) {
        TrieNode* current = root;

        string numStr = to_string(n);

        for (auto c : numStr) {
            if (current->children[c-'0'] == nullptr) {
                current->children[c-'0'] = new TrieNode();
            }
            current = current->children[c-'0'];
        }
    }

    int findLongestPrefix(int num) {
        int length = 0;
        string numStr = to_string(num);
        TrieNode* current = root;

        for (auto c : numStr) {
            if (current->children[c-'0'] == nullptr) break;
                
            current = current->children[c-'0'];
            ++length;
        }

        return length;
    }
};

class Solution {

public:
    int longestCommonPrefix(vector<int>& arr1, vector<int>& arr2) {
        Trie trie; 
        int result = 0;

        // insert all numbers from arr1 into trie
        for (auto num : arr1) trie.insert(num);

        // find longest prefix
        for (auto num : arr2) result = max(result, trie.findLongestPrefix(num));

        return result;
    }
};
