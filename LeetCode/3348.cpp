class Solution {
    string makeSuffix(int size, long long divisor) {
        string res;
        for (int digit = 9; digit > 1; digit--) {
            while (divisor % digit == 0) {
                divisor /= digit;
                res += digit + '0';
            }
        }
        return string(max<int>(size - res.size(), 0), '1') + string(res.rbegin(), res.rend());
    }

public:
    string smallestNumber(string &s, long long divisor) {
        long long d = divisor;
        for (int digit : { 2, 3, 5, 7 })
            while (d % digit == 0)
                d /= digit;
        if (d != 1)
            return "-1";

        vector<long long> suffixDivisor(s.size() + 1, divisor);
        for (int i = 0; i < s.size() && s[i] != '0'; i++)
            suffixDivisor[i + 1] = suffixDivisor[i] / gcd(suffixDivisor[i], s[i] - '0');
        if (suffixDivisor.back() == 1)
            return s;

        int from = s.size() - 1;
        if (int i = s.find('0'); i != -1)
            from = i;

        for (int i = from; i >= 0; i--) {
            int size = s.size() - 1 - i;
            for (char digit = s[i] + 1; digit <= '9'; digit++) {
                long long divisor = suffixDivisor[i] / gcd(suffixDivisor[i], digit - '0');
                if (string suffix = makeSuffix(size, divisor); suffix.size() == size)
                    return s.substr(0, i) + digit + suffix;
            }
        }

        return makeSuffix(s.size() + 1, divisor);
    }
};