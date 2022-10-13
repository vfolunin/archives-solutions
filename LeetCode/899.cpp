class Solution {
public:
    string orderlyQueue(string &s, int k) {
        if (k > 1) {
            sort(s.begin(), s.end());
            return s;
        }
        
        string res = s;
        for (int i = 0; i < s.size(); i++) {
            rotate(s.begin(), s.begin() + 1, s.end());
            res = min(res, s);
        }
        return res;
    }
};