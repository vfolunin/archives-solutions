class Solution {
public:
    int palindromePartition(string &s, int partLimit) {
        vector<vector<int>> cost(s.size(), vector<int>(s.size()));
        
        for (int len = 2; len <= s.size(); len++)
            for (int l = 0, r = len - 1; r < s.size(); l++, r++)
                cost[l][r] = cost[l + 1][r - 1] + (s[l] != s[r]);
        
        vector<vector<int>> res(s.size(), vector<int>(partLimit + 1, 1e9));
        
        for (int i = 0; i < s.size(); i++) {
            res[i][1] = cost[0][i];
            for (int parts = 2; parts <= partLimit; parts++)
                for (int partSize = 1; partSize <= i; partSize++)
                    res[i][parts] = min(res[i][parts], res[i - partSize][parts - 1] + cost[i - partSize + 1][i]);
        }
        
        return res[s.size() - 1][partLimit];
    }
};