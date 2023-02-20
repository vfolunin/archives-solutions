class Solution {
    string dijkstra(vector<vector<int>> &a, int startY, int startX, int finishY, int finishX) {
        vector<vector<int>> dist(a.size(), vector<int>(a[0].size(), 1e9));
        vector<vector<string>> path(a.size(), vector<string>(a[0].size()));
        set<pair<int, pair<int, int>>> q;
        
        dist[startY][startX] = 0;
        q.insert({ 0, { startY, startX } });
        
        vector<int> dy = { -1, 0, 1, 0 };
        vector<int> dx = { 0, 1, 0, -1 };
        string dc = "urdl";
        
        while (!q.empty()) {
            auto [y, x] = q.begin()->second;
            q.erase(q.begin());
                
            for (int d = 0; d < dy.size(); d++) {
                int step = 0;
                while (y + dy[d] * step != finishY || x + dx[d] * step != finishX) {
                    int ty = y + dy[d] * (step + 1);
                    int tx = x + dx[d] * (step + 1);

                    if (0 <= ty && ty < a.size() && 0 <= tx && tx < a[0].size() && !a[ty][tx])
                        step++;
                    else
                        break;
                }

                int ty = y + dy[d] * step;
                int tx = x + dx[d] * step;
                int tDist = dist[y][x] + step;
                string tPath = path[y][x] + dc[d];
            
                if (dist[ty][tx] > tDist || dist[ty][tx] == tDist && path[ty][tx] > tPath) {
                    q.erase({ dist[ty][tx], { ty, tx } });
                    dist[ty][tx] = tDist;
                    path[ty][tx] = tPath;
                    q.insert({ dist[ty][tx], { ty, tx } });
                }
            }
        }
        
        if (dist[finishY][finishX] == 1e9)
            return "impossible";
        else
            return path[finishY][finishX];
    }

public:
    string findShortestWay(vector<vector<int>> &a, vector<int> &start, vector<int> &finish) {
        return dijkstra(a, start[0], start[1], finish[0], finish[1]);
    }
};