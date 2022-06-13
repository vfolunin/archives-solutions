class Solution {
public:
    vector<int> shortestToChar(string s, char c) {
        vector<int> res(s.size());
        
        for (int i = 0, last = -1e9; i < s.size(); i++) {
            if (s[i] == c)
                last = i;
            res[i] = i - last;
        }
        
        for (int i = s.size() - 1, last = 1e9; i >= 0; i--) {
            if (s[i] == c)
                last = i;
            res[i] = min(res[i], last - i);
        }
        
        return res;
    }
};