class Solution {
public:
    long long wonderfulSubstrings(string &s) {
        vector<int> p(s.size());
        unordered_map<int, int> seen = { { 0, 1 } };
        long long res = 0;
        
        for (int i = 0; i < p.size(); i++) {
            if (i)
                p[i] = p[i - 1];
            p[i] ^= 1 << (s[i] - 'a');
            
            res += seen[p[i]];
            for (int bit = 0; bit < 10; bit++)
                res += seen[p[i] ^ (1 << bit)];
            
            seen[p[i]]++;
        }
        
        return res;
    }
};