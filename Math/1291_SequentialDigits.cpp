// Note, there are many ways to do this. The editorial shows a sliding window approach
// THis is an approach that uses recursion to generate only valid numbers within the range.

class Solution {

private:
vector<int> result;

void helper(int cur, int low, int high) {
    if (cur > high) return;
    if (cur >= low) result.push_back(cur);
 
    string num = std::to_string(cur);
    int last = num[num.size()-1] - '0';

    if (last == 9) return;

    cur *= 10;
    cur += last+1;

    helper(cur, low, high);
}

public:
    vector<int> sequentialDigits(int low, int high) {
        for (int i = 1; i <= 9; ++i) {
            helper(i, low, high);
        }

        sort(result.begin(), result.end());
        return result;
    }
};
