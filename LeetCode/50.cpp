class Solution {
public:
    double myPow(double x, long long n) {
        if (n < 0)
            return 1 / myPow(x, -n);
        
        if (!n)
            return 1;
        
        if (n % 2)
            return myPow(x, n - 1) * x;
        
        double r = myPow(x, n / 2);
        return r * r;
    }
};