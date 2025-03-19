class Solution {
public:
    long long countSubstrings(string &s) {
        vector count(s.size(), vector(10, vector<long long>(10)));
        long long res = 0;

        for (int i = 0; i < s.size(); i++) {
            int digit = s[i] - '0';

            for (int divisor = 1; divisor < 10; divisor++) {
                for (int remainder = 0; remainder < divisor; remainder++)
                    if (i)
                        count[i][divisor][(remainder * 10 + digit) % divisor] += count[i - 1][divisor][remainder];
                count[i][divisor][digit % divisor]++;
            }

            if (digit)
                res += count[i][digit][0];
        }

        return res;
    }
};