class Solution {
    int sum(vector<int> &p, int l, int r) {
        return p[r] - (l ? p[l - 1] : 0);
    }

public:
    int stoneGameVII(vector<int> &p) {
        partial_sum(p.begin(), p.end(), p.begin());
        
        vector<vector<pair<int, int>>> win(p.size(), vector<pair<int, int>>(p.size()));

        for (int len = 2; len <= p.size(); len++) {
            for (int l = 0, r = len - 1; r < p.size(); l++, r++) {
                int lBonus = sum(p, l + 1, r);
                int rBonus = sum(p, l, r - 1);
                auto &[la, lb] = win[l + 1][r];
                auto &[ra, rb] = win[l][r - 1];
                
                if (lBonus + lb - la > rBonus + rb - ra)
                    win[l][r] = { lBonus + lb, la };
                else
                    win[l][r] = { rBonus + rb, ra };
            }
        }

        auto &[a, b] = win[0][p.size() - 1];
        return a - b;
    }
};