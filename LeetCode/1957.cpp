class Solution {
public:
    string makeFancyString(string s) {
        string res;
        for (char c : s)
            if (res.size() < 2 || res[res.size() - 2] != c || res[res.size() - 1] != c)
                res += c;
        return res;
    }
};