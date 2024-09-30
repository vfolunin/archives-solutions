class Solution {
    bool hasUniqueDigits(int n) {
        string s = to_string(n);
        return unordered_set<char>(s.begin(), s.end()).size() == s.size();
    }

public:
    int numberCount(int l, int r) {
        int res = 0;
        for (int i = l; i <= r; i++)
            res += hasUniqueDigits(i);
        return res;
    }
};