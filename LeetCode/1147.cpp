class Solution {
public:
    int longestDecomposition(string &s) {
        int res = 0;
        
        string l, r;
        for (int i = 0; i < s.size(); i++) {
            l += s[i];
            r = s[s.size() - i - 1] + r;
            
            if (l == r) {
                l.clear();
                r.clear();
                res++;
            }
        }
        
        return res;
    }
};