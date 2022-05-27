class Solution {
public:
    int minDistance(string a, string b) {
        vector<vector<int>> dist(a.size() + 1, vector<int>(b.size() + 1));
        iota(dist[0].begin(), dist[0].end(), 0);
        for (int ai = 1; ai <= a.size(); ai++) {
            dist[ai][0] = ai;
            for (int bi = 1; bi <= b.size(); bi++) {
                if (a[ai - 1] == b[bi - 1])
                    dist[ai][bi] = dist[ai - 1][bi - 1];
                else
                    dist[ai][bi] = min({ dist[ai - 1][bi - 1], dist[ai - 1][bi], dist[ai][bi - 1] }) + 1;
            }
        }
        return dist[a.size()][b.size()];
    }
};