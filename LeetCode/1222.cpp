class Solution {
public:
    vector<vector<int>> queensAttacktheKing(vector<vector<int>> &queens, vector<int> &king) {
        set<vector<int>> queenSet(queens.begin(), queens.end());
        int ky = king[0], kx = king[1];
        
        vector<int> dy = { -1, -1, -1, 0, 1, 1, 1, 0 };
        vector<int> dx = { -1, 0, 1, 1, 1, 0, -1, -1 };
        
        vector<vector<int>> res;
        
        for (int d = 0; d < dy.size(); d++) {
            for (int step = 1; step < 8; step++) {
                int ty = ky + dy[d] * step;
                int tx = kx + dx[d] * step;
                if (queenSet.count({ ty, tx })) {
                    res.push_back({ ty, tx });
                    break;
                }
            }
        }
        
        return res;
    }
};