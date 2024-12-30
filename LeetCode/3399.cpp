class Solution {
    bool can1(string &s, int opLimit) {
        int ops0 = 0, ops1 = 0;
        for (int i = 0; i < s.size(); i++) {
            ops0 += s[i] != i % 2 + '0';
            ops1 += s[i] == i % 2 + '0';
        }
        return ops0 <= opLimit || ops1 <= opLimit;
    }

    bool can(string &s, int rowLimit, int opLimit) {
        vector<int> parts(1, 1);
        for (int i = 1; i < s.size(); i++) {
            if (s[i - 1] == s[i])
                parts.back()++;
            else
                parts.push_back(1);
        }

        int ops = 0;
        for (int part : parts)
            ops += part / (rowLimit + 1);
        return ops <= opLimit;
    }

public:
    int minLength(string &s, int opLimit) {
        if (can1(s, opLimit))
            return 1;
 
        int l = 1, r = s.size();
        while (l + 1 < r) {
            int m = l + (r - l) / 2;
            if (can(s, m, opLimit))
                r = m;
            else
                l = m;
        }
        return r;
    }
};