class Solution {
public:
    bool isUgly(int n) {
        if (n <= 0)
            return 0;
        for (int d : { 2, 3, 5 })
            while (n % d == 0)
                n /= d;
        return n == 1;
    }
};