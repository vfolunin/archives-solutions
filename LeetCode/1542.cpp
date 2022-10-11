class Solution {
public:
    int longestAwesome(string &s) {
        vector<int> first(1 << 10, -2);
        first[0] = -1;
        
        int mask = 0, res = 1;
        
        for (int i = 0; i < s.size(); i++) {
            mask ^= (1 << (s[i] - '0'));
            
            if (first[mask] != -2)
                res = max(res, i - first[mask]);
            
            for (int bit = 0; bit < 10; bit++)
                if (first[mask ^ (1 << bit)] != -2)
                    res = max(res, i - first[mask ^ (1 << bit)]);
        
            if (first[mask] == -2)
                first[mask] = i;
        }
        
        return res;
    }
};