class Solution {
    int ones(long long n) {
        int res = 0;
        while (n) {
            res++;
            n &= n - 1;
        }
        return res;
    }

public:
    int makeTheIntegerZero(long long a, long long b) {
        for (int ops = 1; a > b; ops++) {
            a -= b;
            
            if (ones(a) <= ops && ops <= a)
                return ops;
        }

        return -1;
    }
};