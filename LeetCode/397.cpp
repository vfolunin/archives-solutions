class Solution {
public:
    int integerReplacement(long long n) {
        if (n == 1)
            return 0;
        
        if (n % 2 == 0)
            return 1 + integerReplacement(n / 2);
        else if (n > 3 && n % 4 == 3)
            return 1 + integerReplacement(n + 1);
        else
            return 1 + integerReplacement(n - 1);
    }
};