class Solution {
public:
    int minScoreTriangulation(vector<int> &a) {
        vector<vector<int>> score(a.size(), vector<int>(a.size()));
        
        for (int i = 0; i + 2 < a.size(); i++)
            score[i][i + 2] = a[i] * a[i + 1] * a[i + 2];
        
        for (int len = 4; len <= a.size(); len++) {
            for (int l = 0, r = len - 1; r < a.size(); l++, r++) {
                score[l][r] = 1e9;
                for (int m = l + 1; m < r; m++)
                    score[l][r] = min(score[l][r], score[l][m] + score[m][r] + a[l] * a[m] * a[r]);
            }
        }
        
        return score[0][a.size() - 1];
    }
};