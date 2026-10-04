class Solution {
public:
    int minRotations(string &s) {
        s = "0" + s;
        int res = 0;
        for (int i = 0; i + 1 < s.size(); i++) {
            int delta = abs(s[i] - s[i + 1]);
            delta = min(delta, 10 - delta);
            res += delta;
        }
        return res;
    }
};