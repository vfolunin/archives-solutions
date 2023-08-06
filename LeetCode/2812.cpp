class Solution {
    vector<vector<int>> bfs1(vector<vector<int>> &a) {
        vector<vector<int>> dist(a.size(), vector<int>(a[0].size(), 1e9));
        queue<pair<int, int>> q;

        for (int y = 0; y < a.size(); y++) {
            for (int x = 0; x < a[0].size(); x++) {
                if (a[y][x]) {
                    dist[y][x] = 0;
                    q.push({ y, x });
                }
            }
        }
        
        vector<int> dy = { -1, 0, 1, 0 };
        vector<int> dx = { 0, 1, 0, -1 };

        while (!q.empty()) {
            auto [y, x] = q.front();
            q.pop();

            for (int d = 0; d < dy.size(); d++) {
                int ty = y + dy[d];
                int tx = x + dx[d];

                if (0 <= ty && ty < a.size() && 0 <= tx && tx < a[0].size() && dist[ty][tx] > dist[y][x] + 1) {
                    dist[ty][tx] = dist[y][x] + 1;
                    q.push({ ty, tx });
                }
            }
        }

        return dist;
    }
    
    bool bfs2(vector<vector<int>> &a, int limit) {
        vector<vector<int>> dist(a.size(), vector<int>(a[0].size(), 1e9));
        queue<pair<int, int>> q;
        
        if (a[0][0] < limit)
            return 0;

        dist[0][0] = 0;
        q.push({ 0, 0 });
        
        vector<int> dy = { -1, 0, 1, 0 };
        vector<int> dx = { 0, 1, 0, -1 };

        while (!q.empty()) {
            auto [y, x] = q.front();
            q.pop();
            
            if (y == a.size() - 1 && x == a[0].size() - 1)
                return 1;

            for (int d = 0; d < dy.size(); d++) {
                int ty = y + dy[d];
                int tx = x + dx[d];

                if (0 <= ty && ty < a.size() && 0 <= tx && tx < a[0].size() && a[ty][tx] >= limit && dist[ty][tx] > dist[y][x] + 1) {
                    dist[ty][tx] = dist[y][x] + 1;
                    q.push({ ty, tx });
                }
            }
        }

        return 0;
    }
    
public:
    int maximumSafenessFactor(vector<vector<int>> &a) {
        vector<vector<int>> dist = bfs1(a);
        
        int l = 0, r = 1000;
        while (l + 1 < r) {
            int m = l + (r - l) / 2;
            if (bfs2(dist, m))
                l = m;
            else
                r = m;
        }
        return l;
    }
};