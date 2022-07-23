class Solution {
    int sum(vector<int> &p, int l, int r) {
        return p[r] - (l ? p[l - 1] : 0);
    }
    
public:
    bool stoneGame(vector<int> &p) {
        partial_sum(p.begin(), p.end(), p.begin());
        
        vector<vector<int>> win(p.size(), vector<int>(p.size()));
 
        for (int i = 0; i < p.size(); i++)
            win[i][i] = sum(p, i, i);

        for (int len = 2; len <= p.size(); len++)
            for (int l = 0, r = len - 1; r < p.size(); l++, r++)
                win[l][r] = sum(p, l, r) - min(win[l + 1][r], win[l][r - 1]);

        return win[0][p.size() - 1] * 2 >= p.back();
    }
};