class Solution {
    vector<set<long long>> preparePalindromes() {
        vector<set<long long>> palindromes(2);

        for (int palindrome = 1; palindrome <= 9; palindrome++)
            palindromes[palindrome % 2].insert(palindrome);

        for (int half = 1; half < 1e5; half++) {
            string l = to_string(half);
            string r(l.rbegin(), l.rend());
            long long palindrome = stoll(l + r);
            palindromes[palindrome % 2].insert(palindrome);

            for (char m = '0'; m <= '9'; m++) {
                long long palindrome = stoll(l + m + r);
                palindromes[palindrome % 2].insert(palindrome);
            }
        }

        return palindromes;
    }

public:
    long long minOperations(vector<int> &a) {
        static vector<set<long long>> palindromes = preparePalindromes();
        long long ops = 0;

        for (int value : a) {
            auto rIt = palindromes[value % 2].upper_bound(value);
            auto lIt = prev(rIt);
            ops += min(value - *lIt, *rIt - value) / 2;
        }

        return ops;
    }
};