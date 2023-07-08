class Solution {
    bool isPowerOf5(string &s, int from, int len) {
        int value = stoi(s.substr(from, len), 0, 2);
        while (value % 5 == 0)
            value /= 5;
        return value == 1;
    }

public:
    int minimumBeautifulSubstrings(string &s) {
        vector<int> res(s.size() + 1, 1e9);
        res[0] = 0;
        
        for (int len = 1; len <= s.size(); len++)
            for (int part = 1; part <= len; part++)
                if (s[len - part] == '1' && isPowerOf5(s, len - part, part))
                    res[len] = min(res[len], res[len - part] + 1);
        
        return res.back() != 1e9 ? res.back() : -1;
    }
};