class Solution {
    vector<vector<int>> bfs(int startY, int startX) {
        vector<vector<int>> dist(50, vector<int>(50, 1e9));
        queue<pair<int, int>> q;
        
        dist[startY][startX] = 0;
        q.push({ startY, startX });
        
        vector<int> dy = { -2, -2, -1, 1, 2, 2, 1, -1 };
        vector<int> dx = { -1, 1, 2, 2, 1, -1, -2, -2 };
        
        while (!q.empty()) {
            auto [y, x] = q.front();
            q.pop();
                
            for (int d = 0; d < dy.size(); d++) {
                int ty = y + dy[d];
                int tx = x + dx[d];
                
                if (0 <= ty && ty < 50 && 0 <= tx && tx < 50 && dist[ty][tx] > dist[y][x] + 1) {
                    dist[ty][tx] = dist[y][x] + 1;
                    q.push({ ty, tx });
                }
            }
        }
        
        return dist;
    }

    int rec(vector<vector<int>> &dist, int mask, int last, vector<vector<int>> &memo) {
        int &res = memo[mask][last];
        if (res != -1)
            return res;
        
        if (!(mask & (mask - 1)))
            return res = 0;
        
        int turn = 1;
        for (int bit = 0; bit < dist.size(); bit++)
            if (!(mask & (1 << bit)))
                turn = 3 - turn;
        
        res = turn == 1 ? -1e9 : 1e9;
        for (int next = 0; next < dist.size(); next++) {
            if (last != next && (mask & (1 << next))) {
                if (turn == 1)
                    res = max(res, dist[last][next] + rec(dist, mask ^ (1 << last), next, memo));
                else
                    res = min(res, dist[last][next] + rec(dist, mask ^ (1 << last), next, memo));
            }
        }
        return res;
    }

public:
    int maxMoves(int y, int x, vector<vector<int>> &cells) {
        cells.insert(cells.begin(), { y, x });

        vector<vector<int>> dist(cells.size(), vector<int>(cells.size()));
        for (int a = 0; a < cells.size(); a++) {
            vector<vector<int>> distA = bfs(cells[a][0], cells[a][1]);
            for (int b = 0; b < cells.size(); b++)
                dist[a][b] = distA[cells[b][0]][cells[b][1]];
        }

        vector<vector<int>> memo(1 << dist.size(), vector<int>(dist.size(), -1));
        return rec(dist, (1 << dist.size()) - 1, 0, memo);
    }
};