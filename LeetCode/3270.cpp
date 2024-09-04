class Solution {
    string getString(int value) {
        string s = to_string(value);
        return string(4 - s.size(), '0') + s;
    }

public:
    int generateKey(int a, int b, int c) {
        string sa = getString(a);
        string sb = getString(b);
        string res = getString(c);

        for (int i = 0; i < res.size(); i++)
            res[i] = min({ res[i], sa[i], sb[i] });

        return stoi(res);
    }
};