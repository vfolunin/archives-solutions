class Solution {
    void rec(string &s, int i, int value, int sum, set<int> &sums) {
        if (i == s.size()) {
            sum += value;
            sums.insert(sum);
            return;
        }
        rec(s, i + 1, value * 10 + s[i] - '0', sum, sums);
        rec(s, i + 1, s[i] - '0', sum + value, sums);
    }
    
    bool isPunishmentNumber(int n) {
        string s = to_string(n * n);
        set<int> sums;
        rec(s, 0, 0, 0, sums);
        return sums.count(n);
    }
    
public:
    int punishmentNumber(int n) {
        int res = 0;
        for (int i = 1; i <= n; i++)
            if (isPunishmentNumber(i))
                res += i * i;
        return res;
    }
};