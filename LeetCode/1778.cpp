class Solution {
    inline static const vector<int> DY = { -1, 0, 1, 0 };
    inline static const vector<int> DX = { 0, 1, 0, -1 };
    inline static const string DC = "URDL";

    void dfs(GridMaster &master, vector<vector<int>> &a, int y, int x) {
        a[y][x] = 1;
        if (master.isTarget())
            a[y][x] = -1;

        for (auto d = 0; d < DY.size(); d++) {
            int ty = y + DY[d];
            int tx = x + DX[d];

            if (!a[ty][tx] && master.canMove(DC[d])) {
                master.move(DC[d]);
                dfs(master, a, ty, tx);
                master.move(DC[(d + DC.size() / 2) % DC.size()]);
            }
        }
    }

    int bfs(vector<vector<int>> &a, int startY, int startX) {
        vector<vector<int>> dist(a.size(), vector<int>(a[0].size(), 1e9));
        queue<pair<int, int>> q;
        
        dist[startY][startX] = 0;
        q.push({ startY, startX });
        
        while (!q.empty()) {
            auto [y, x] = q.front();
            q.pop();

            if (a[y][x] == -1)
                return dist[y][x];
                
            for (int d = 0; d < DY.size(); d++) {
                int ty = y + DY[d];
                int tx = x + DX[d];
                
                if (a[ty][tx] && dist[ty][tx] > dist[y][x] + 1) {
                    dist[ty][tx] = dist[y][x] + 1;
                    q.push({ ty, tx });
                }
            }
        }
        
        return -1;
    }

public:
    int findShortestPath(GridMaster &master) {
        vector<vector<int>> a(1001, vector<int>(1001));
        dfs(master, a, 500, 500);
        return bfs(a, 500, 500);
    }
};