class Solution {
    vector<vector<int>> bfs(vector<vector<int>> &a, int startY, int startX) {
        int h = a.size(), w = a[0].size();

        vector<vector<int>> dist(h, vector<int>(w, 1e9));
        dist[startY][startX] = 0;

        queue<pair<int, int>> q;
        q.push({ startY, startX });

        vector<int> dy = { -1, 0, 1, 0 };
        vector<int> dx = { 0, 1, 0, -1 };
        
        while (!q.empty()) {
            auto [y, x] = q.front();
            q.pop();
            
            for (int d = 0; d < dy.size(); d++) {
                int ty = y + dy[d];
                int tx = x + dx[d];

                if (0 <= ty && ty < h && 0 <= tx && tx < w && !a[ty][tx] && dist[ty][tx] == 1e9) {
                    dist[ty][tx] = dist[y][x] + 1;
                    q.push({ ty, tx });
                }
            }
        }
        
        return dist;
    }

public:
    int shortestDistance(vector<vector<int>> &a) {
        int h = a.size(), w = a[0].size();

        vector<pair<int, int>> start;
        for (int y = 0; y < h; y++)
            for (int x = 0; x < w; x++)
                if (a[y][x] == 1)
                    start.push_back({ y, x });
        
        vector<vector<int>> sumDist(h, vector<int>(w));
        for (auto &[startY, startX] : start) {
            vector<vector<int>> dist = bfs(a, startY, startX);
            for (int y = 0; y < h; y++) {
                for (int x = 0; x < w; x++) {
                    if (!a[y][x]) {
                        if (dist[y][x] == 1e9)
                            a[y][x] = 2;
                        else
                            sumDist[y][x] += dist[y][x];
                    }
                }
            }
        }

        int res = -1;
        for (int y = 0; y < h; y++)
            for (int x = 0; x < w; x++)
                if (!a[y][x] && (res == -1 || res > sumDist[y][x]))
                    res = sumDist[y][x];
        return res;
    }
};