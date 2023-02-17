class Solution {
public:
    long long fixedRatio(string &s, int w0, int w1) {
        long long diff = 0, res = 0;
        unordered_map<long long, long long> seen = { { 0, 1 } };
        for (char c : s) {
            diff += c == '1' ? w0 : -w1;
            res += seen[diff];
            seen[diff]++;
        }
        return res;
    }
};