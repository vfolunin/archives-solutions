class Solution {
public:
    int maxPathScore(vector<vector<int>> &a, int limit) {
        vector maxScore(a.size(), vector(a[0].size(), vector<int>(limit + 1, -1)));
        fill(maxScore[0][0].begin(), maxScore[0][0].end(), 0);

        for (int y = 0; y < a.size(); y++) {
            for (int x = 0; x < a[0].size(); x++) {
                for (int cost = 0; cost <= limit; cost++) {
                    int prevCost = cost - (bool)a[y][x];
                    if (prevCost < 0)
                        continue;
                    
                    if (y && maxScore[y - 1][x][prevCost] != -1)
                        maxScore[y][x][cost] = max(maxScore[y][x][cost], maxScore[y - 1][x][prevCost] + a[y][x]);
                    if (x && maxScore[y][x - 1][prevCost] != -1)
                        maxScore[y][x][cost] = max(maxScore[y][x][cost], maxScore[y][x - 1][prevCost] + a[y][x]);
                }
            }
        }

        return *max_element(maxScore.back().back().begin(), maxScore.back().back().end());
    }
};