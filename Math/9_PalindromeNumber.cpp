class Solution {
public:
    bool isPalindrome(int x) {
        if (x < 0) return false;

        // find the divisor for modulo and fivision operations
        long long div = 1;
        while (x >= div * 10) {
            div *= 10;
        }

        while (x > 0) {
            int left = x / div;
            int right = x % 10;

            if (left != right) return false;

            // remove the first (x%div) and last (x/10) digits
            x = (x % div) / 10;

            // shrink divisor by two digits
            div /= 100;
        }

        return true;
    }
};
