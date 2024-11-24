class Solution {
public:
    int maxCollectedFruits(vector<vector<int>> &a) {
        vector<vector<int>> bonus1(a.size(), vector<int>(a.size(), -1e9));
        bonus1[0][a.size() - 1] = a[0][a.size() - 1];
        for (int y = 1; y < a.size(); y++)
            for (int x = y + 1; x < a.size(); x++)
                for (int px = x - 1; px <= x + 1 && px < a.size(); px++)
                    bonus1[y][x] = max(bonus1[y][x], bonus1[y - 1][px] + a[y][x]);
        
        vector<vector<int>> bonus2(a.size(), vector<int>(a.size(), -1e9));
        bonus2[a.size() - 1][0] = a[a.size() - 1][0];
        for (int x = 1; x < a.size(); x++)
            for (int y = x + 1; y < a.size(); y++)
                for (int py = y - 1; py <= y + 1 && py < a.size(); py++)
                    bonus2[y][x] = max(bonus2[y][x], bonus2[py][x - 1] + a[y][x]);
        
        int res = 0;
        for (int i = 0; i < a.size(); i++)
            res += a[i][i];
        res += bonus1[a.size() - 2][a.size() - 1];
        res += bonus2[a.size() - 1][a.size() - 2];
        return res;
    }
};