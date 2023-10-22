class Solution {
    int palindromeCost(string &s, int l, int r, int d) {
        int res = 0;
        for ( ; l < r; l += d, r -= d)
            res += s[l] != s[r];
        return res;
    }

    int cost(string &s, int l, int r, int d) {      
        int res = 0;
        for (int i = 0; i < d; i++) {
            int curL = l + i;
            int curR = curL + (r - l) / d * d;
            res += palindromeCost(s, curL, curR, d);
        }
        return res;
    }
    
    int cost(string &s, int l, int r, vector<vector<int>> &memo) {
        int &res = memo[l][r];
        if (res != -1)
            return res;

        int len = r - l + 1;
        res = 1e9;
        
        for (int d = 1; d * d <= len; d++) {
            if (len % d)
                continue;
            
            res = min(res, cost(s, l, r, d));
            if (d != 1 && d * d < len)
                res = min(res, cost(s, l, r, len / d));
        }
        
        return res;
    }
    
public:
    int minimumChanges(string &s, int partCount) {
        vector<vector<int>> res(s.size() + 1, vector<int>(partCount + 1, 1e9));
        vector<vector<int>> memo(s.size(), vector<int>(s.size(), -1));
        
        for (int size = 1; size <= s.size(); size++) {
            res[size][1] = cost(s, 0, size - 1, memo);
            
            for (int parts = 2; parts <= partCount; parts++)
                for (int partSize = 2; (parts - 1) * 2 + partSize <= size; partSize++)
                    if (res[size - partSize][parts - 1] != 1e9)
                        res[size][parts] = min(res[size][parts], res[size - partSize][parts - 1] + cost(s, size - partSize, size - 1, memo));
        }
        
        return res[s.size()][partCount];
    }
};