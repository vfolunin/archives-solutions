class Solution {
    int getDelta(char a, char b) {
        int delta = abs(a - b);
        return min(delta, 10 - delta);
    }

public:
    int minRotations(int size, string &s) {
        s = "0" + s;

        int baseRes = 0;
        for (int i = 0; i + 1 < s.size(); i++)
            baseRes += getDelta(s[i], s[i + 1]);

        int res = baseRes;
        for (int i = 0; i + 1 < s.size(); i++) 
            res = min(res, baseRes - getDelta(s[i], s[i + 1]) + getDelta(s[i], s.back()));
        return res;
    }
};