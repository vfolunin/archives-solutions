class Solution {
public:
    string mergeAlternately(string a, string b) {
        string res;
        for (int i = 0; i < a.size() && i < b.size(); i++) {
            res += a[i];
            res += b[i];
        }
        if (a.size() < b.size())
            res += b.substr(a.size());
        if (b.size() < a.size())
            res += a.substr(b.size());
        return res;
    }
};