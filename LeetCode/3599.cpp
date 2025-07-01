class Solution {
    int getXor(vector<int> &p, int l, int r) {
        return p[r] ^ (l ? p[l - 1] : 0);
    }

public:
    int minXor(vector<int> &a, int partCount) {
        vector<int> p = a;
        for (int i = 1; i < p.size(); i++)
            p[i] = p[i - 1] ^ a[i];
        
        vector<vector<int>> res(a.size(), vector<int>(partCount + 1, 2e9));
        for (int i = 0; i < a.size(); i++) {
            res[i][1] = getXor(p, 0, i);
            for (int parts = 2; parts <= partCount; parts++)
                for (int partSize = 1; partSize <= i; partSize++)
                    res[i][parts] = min(res[i][parts], max(res[i - partSize][parts - 1], getXor(p, i - partSize + 1, i)));
        }
        return res.back().back();
    }
};