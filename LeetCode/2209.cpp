class Solution {
public:
    int minimumWhiteTiles(string &s, int carpetCount, int width) {
        vector<vector<int>> res(s.size() + 1, vector<int>(carpetCount + 1));

        for (int len = 1; len <= s.size(); len++)
            res[len][0] = res[len - 1][0] + (s[len - 1] == '1');
        
        for (int carpets = 1; carpets <= carpetCount; carpets++)
            for (int len = width + 1; len <= s.size(); len++)
                res[len][carpets] = min(res[len - 1][carpets] + (s[len - 1] == '1'), res[len - width][carpets - 1]);
        
        return res[s.size()][carpetCount];
    }
};