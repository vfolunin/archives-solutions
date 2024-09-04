class Solution {
    long long powerOfTen(int p) {
        long long res = 1;
        for (int i = 0; i < p; i++)
            res *= 10;
        return res;
    }

    bool divides(string &s, int divisor) {
        int remainder = 0;
        for (char c : s)
            remainder = (remainder * 10 + c - '0') % divisor;
        return !remainder;
    }

    void tryAdd(string s, int divisor, unordered_set<string> &res) {
        if (divides(s, divisor)) {
            sort(s.begin(), s.end());
            res.insert(s);
        }
    }

    unordered_set<string> generatePalindromes(int size, int divisor) {
        unordered_set<string> res;

        if (size == 1) {
            for (char digit = '1'; digit <= '9'; digit++)
                tryAdd(string(1, digit), divisor, res);
            return res;
        }

        int from = powerOfTen(size / 2 - 1), to = powerOfTen(size / 2);
        for (int value = from; value < to; value++) {
            string l = to_string(value);
            string r = { l.rbegin(), l.rend() };

            if (size % 2) {
                for (char digit = '0'; digit <= '9'; digit++)
                    tryAdd(l + string(1, digit) + r, divisor, res);
            } else {
                tryAdd(l + r, divisor, res);
            }
        }

        return res;
    }

    long long factorial(int n) {
        long long res = 1;
        for (int i = 2; i <= n; i++)
            res *= i;
        return res;
    }

    long long anagramCount(const string &s) {
        vector<int> count(10);
        for (char c : s)
            count[c - '0']++;

        long long res = factorial(s.size() - 1) * (s.size() - count[0]);
        for (int count : count)
            res /= factorial(count);
        return res;
    }

public:
    long long countGoodIntegers(int size, int divisor) {
        long long res = 0;
        for (const string &s : generatePalindromes(size, divisor))
            res += anagramCount(s);
        return res;
    }
};