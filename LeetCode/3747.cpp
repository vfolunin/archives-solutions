class Solution {
public:
    long long countDistinct(long long n) {
        string s = to_string(n);

        vector<long long> power(s.size(), 1);
        for (int size = 1; size < power.size(); size++)
            power[size] = power[size - 1] * 9;

        long long res = 0;
        for (int size = 1; size < s.size(); size++)
            res += power[size];
        for (int i = 0; i < s.size(); i++) {
            if (s[i] == '0')
                break;
            res += (s[i] - '0' - 1) * power[s.size() - 1 - i];
        }
        res += !count(s.begin(), s.end(), '0');
        return res;
    }
};