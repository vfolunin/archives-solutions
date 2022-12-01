class Solution {
    const long long MOD = 1e9 + 7;
    
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

    int rec(int size, string &l, string &r, string &s,
            int i, int lMatch, int rMatch, int border, 
            vector<int> &p, vector<vector<vector<vector<int>>>> &memo) {
        int &res = memo[i][lMatch][rMatch][border];
        if (res != -1)
            return res;
        
        if (border == s.size())
            return res = 0;
        
        if (i == size)
            return res = 1;        
        
        char minC = lMatch ? l[i] : 'a';
        char maxC = rMatch ? r[i] : 'z';
        res = 0;
        
        for (char c = minC; c <= maxC; c++) {
            int nextBorder = border;
            while (nextBorder > 0 && c != s[nextBorder])
                nextBorder = p[nextBorder - 1];
            nextBorder += (c == s[nextBorder]);
            
            int nextLMatch = lMatch && c == minC;
            int nextRMatch = rMatch && c == maxC;
            
            res = (res + rec(size, l, r, s, i + 1, nextLMatch, nextRMatch, nextBorder, p, memo)) % MOD;
        }
        
        return res;
    }
    
public:
    int findGoodStrings(int size, string &l, string &r, string &s) {
        vector<int> p = prefixFunction(s);
        vector<vector<vector<vector<int>>>> memo(size + 1,
            vector<vector<vector<int>>>(2, vector<vector<int>>(2, vector<int>(s.size() + 1, -1))));
        return rec(size, l, r, s, 0, 1, 1, 0, p, memo);
    }
};