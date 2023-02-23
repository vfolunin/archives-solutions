class Solution {
    inline static const vector<int> DY = { -1, 0, 1, 0 };
    inline static const vector<int> DX = { 0, 1, 0, -1 };
    inline static const string DC = "URDL";

    void dfs(GridMaster &master, vector<vector<int>> &a, int y, int x, int &finishY, int &finishX) {
        if (master.isTarget()) {
            finishY = y;
            finishX = x;
        }

        for (auto d = 0; d < DY.size(); d++) {
            int ty = y + DY[d];
            int tx = x + DX[d];

            if (!a[ty][tx] && master.canMove(DC[d])) {
                a[ty][tx] = master.move(DC[d]);
                dfs(master, a, ty, tx, finishY, finishX);
                master.move(DC[(d + DC.size() / 2) % DC.size()]);
            }
        }
    }

    int dijkstra(vector<vector<int>> &a, int startY, int startX, int finishY, int finishX) {
        vector<vector<int>> dist(a.size(), vector<int>(a[0].size(), 1e9));
        set<pair<int, pair<int, int>>> q;
        
        dist[startY][startX] = 0;
        q.insert({ 0, { startY, startX } });
        
        while (!q.empty()) {
            auto [y, x] = q.begin()->second;
            q.erase(q.begin());

            if (y == finishY && x == finishX)
                return dist[y][x];
                
            for (int d = 0; d < DY.size(); d++) {
                int ty = y + DY[d];
                int tx = x + DX[d];
                
                if (a[ty][tx] && dist[ty][tx] > dist[y][x] + a[ty][tx]) {
                    q.erase({ dist[ty][tx], { ty, tx } });
                    dist[ty][tx] = dist[y][x] + a[ty][tx];
                    q.insert({ dist[ty][tx], { ty, tx } });
                }
            }
        }
        
        return -1;
    }

public:
    int findShortestPath(GridMaster &master) {
        vector<vector<int>> a(201, vector<int>(201));
        int finishY, finishX;
        dfs(master, a, 100, 100, finishY, finishX);
        return dijkstra(a, 100, 100, finishY, finishX);
    }
};