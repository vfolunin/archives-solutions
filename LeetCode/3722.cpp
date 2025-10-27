class Solution {
public:
    string lexSmallest(string &s) {
        string res = s;
        for (int i = 0; i < s.size(); i++) {
            string l = s.substr(0, i), r = s.substr(i);
            res = min(res, string(l.rbegin(), l.rend()) + r);
            res = min(res, l + string(r.rbegin(), r.rend()));
        }
        return res;
    }
};