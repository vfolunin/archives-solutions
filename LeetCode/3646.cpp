class Solution {
    void rec(string &digits, int from, int odd, vector<long long> &specialNumbers) {
        for (int digit = from; digit < 10; digit++) {
            if (digits.size() * 2 + digit > 16 || digit % 2 && odd)
                continue;
            
            for (int i = 0; i < digit / 2; i++)
                digits.push_back(digit + '0');
            
            rec(digits, digit + 1, digit % 2 ? digit : odd, specialNumbers);

            for (int i = 0; i < digit / 2; i++)
                digits.pop_back();
        }

        do {
            string rDigits(digits.rbegin(), digits.rend());
            if (!digits.empty() || odd)
                specialNumbers.push_back(stoll(digits + (odd ? string(1, odd + '0') : "") + rDigits));
        } while (next_permutation(digits.begin(), digits.end()));
    }

public:
    long long specialPalindrome(long long n) {
        string digits;
        vector<long long> specialNumbers;
        rec(digits, 1, 0, specialNumbers);
        sort(specialNumbers.begin(), specialNumbers.end());

        return *upper_bound(specialNumbers.begin(), specialNumbers.end(), n);
    }
};