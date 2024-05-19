class Solution {
public:
    long long sumDigitDifferences(vector<int> &a) {
        vector<vector<int>> count(to_string(a[0]).size(), vector<int>(10));
        for (int value : a) {
            string s = to_string(value);
            for (int i = 0; i < s.size(); i++)
                count[i][s[i] - '0']++;
        }

        long long res = 0;
        for (int i = 0; i < count.size(); i++)
            for (int digit = 0; digit < count[i].size(); digit++)
                res += count[i][digit] * (a.size() - count[i][digit]);
        return res / 2;
    }
};