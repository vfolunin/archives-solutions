class Solution {
    int getValue(string &s) {
        int res = 0;
        for (char c : s) {
            if (isdigit(c))
                res = res * 10 + c - '0';
            else
                return s.size();
        }
        return res;
    }

public:
    int maximumValue(vector<string> &a) {
        int res = 0;
        for (string &s : a)
            res = max(res, getValue(s));
        return res;
    }
};