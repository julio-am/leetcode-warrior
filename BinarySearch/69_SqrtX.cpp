class Solution {
public:
    int mySqrt(int x) {
        int l = 0, r = x;
        int result = 0;

        while (l <= r) {
            int mid = l + (r-l) / 2;

            if ((long long)mid * mid == x) return mid;

            if ((long long)mid * mid < x) {
                result = mid;
                l = mid+1;
            }

            else r = mid-1;
        }

        return result;
    }
};
