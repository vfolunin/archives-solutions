class Solution {
    int factorial(int n) {
        static vector<int> memo(10);
        int &res = memo[n];
        if (res)
            return res;

        if (n <= 1)
            return res = 1;

        return res = factorial(n - 1) * n;
    }

    string getSortedDigits(int n) {
        string s = to_string(n);
        sort(s.begin(), s.end());
        return s;
    }

public:
    bool isDigitorialPermutation(int n) {
        string digits = getSortedDigits(n);

        int sum = 0;
        for (; n; n /= 10)
            sum += factorial(n % 10);

        return getSortedDigits(sum) == digits;
    }
};