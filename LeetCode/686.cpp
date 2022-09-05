class Solution {
    vector<int> prefixFunction(const string &s) {
        vector<int> p(s.size());
        for (int i = 1; i < s.size(); i++) {
            int border = p[i - 1];
            while (border > 0 && s[i] != s[border])
                border = p[border - 1];
            p[i] = border + (s[i] == s[border]);
        }
        return p;
    }
    
public:
    int repeatedStringMatch(string &a, string &b) {
        vector<int> p = prefixFunction(b);
        
        int res = 1, prevBorder = 0;
        
        do {
            for (int i = 0; i < a.size(); i++) {
                int border = prevBorder;
                while (border > 0 && a[i] != b[border])
                    border = p[border - 1];
                border += (a[i] == b[border]);

                if (border == b.size())
                    return res;

                prevBorder = border;
            }
            
            res++;
        } while (res <= 2 || res * a.size() < 3 * b.size());
        
        return -1;
    }
};