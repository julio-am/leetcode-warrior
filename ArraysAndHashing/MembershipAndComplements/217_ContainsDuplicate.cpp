#include <unordered_set>
using namespace std;
class Solution {
public:
    bool containsDuplicateBasic(vector<int>& nums) {
        unordered_set<int, int> seen;
        
        for (auto num : nums) {
            if (seen.find(num) != seen.end()) return true;
        }
        return false;
    }

    bool containsDuplicateFancy(vector<int>& nums) {
        return nums.size() > unordered_set<int>(nums.begin(), nums.end()).size();
    }
};
