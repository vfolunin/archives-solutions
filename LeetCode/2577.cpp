class Solution {
public:
    int minimumTime(vector<vector<int>> &a) {
        if (a[0][1] > 1 && a[1][0] > 1)
            return -1;
        
        int h = a.size(), w = a[0].size();

        vector<vector<vector<int>>> dist(h, vector<vector<int>>(w, vector<int>(2, 1e9)));
        set<pair<int, tuple<int, int, int>>> q;

        dist[0][0][0] = 0;        
        q.insert({ 0, { 0, 0, 0 } });

        vector<int> dy = { -1, 0, 1, 0 };
        vector<int> dx = { 0, 1, 0, -1 };

        while (!q.empty()) {
            auto [y, x, odd] = q.begin()->second;
            q.erase(q.begin());
            
            for (int d = 0; d < dy.size(); d++) {
                int ty = y + dy[d];
                int tx = x + dx[d];
                
                if (ty < 0 || ty >= h || tx < 0 || tx >= w)
                    continue;
                
                int tOdd = !odd;
                int tDist = max(dist[y][x][odd] + 1, a[ty][tx] + (a[ty][tx] % 2 == odd));

                if (dist[ty][tx][tOdd] > tDist) {
                    q.erase({ tDist, { ty, tx, tOdd } });
                    dist[ty][tx][tOdd] = tDist;
                    q.insert({ tDist, { ty, tx, tOdd } });
                }
            }
        }
        
        int res = min(dist[h - 1][w - 1][0], dist[h - 1][w - 1][1]);
        return res != 1e9 ? res : -1;
    }
};