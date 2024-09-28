class Solution {
public:
    double myPow(double x, int n) {
        return wowOk(x, (long long) n);
    }

private:
    double wowOk(double x, long long n) {
        if (n == 0)
            return 1;  

        if (n < 0)
            return 1.0 / wowOk(x, -1.0 * n);
        
        if (n%2 == 0) return wowOk(x*x, n/2);
        else return x * wowOk(x*x, (n-1)/2);
    }
};
