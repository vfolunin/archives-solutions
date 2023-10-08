class Solution {
    vector<int> dy = { -1, 0, 1, 0 };
    vector<int> dx = { 0, 1, 0, -1 };

    vector<vector<int>> bfs(vector<vector<string>> &a, vector<pair<int, int>> &start) {
        vector<vector<int>> dist(a.size(), vector<int>(a[0].size(), 1e9));
        queue<pair<int, int>> q;
        
        for (auto &[startY, startX] : start) {
            dist[startY][startX] = 0;
            q.push({ startY, startX });
        }
        
        while (!q.empty()) {
            auto [y, x] = q.front();
            q.pop();
                
            for (int d = 0; d < dy.size(); d++) {
                int ty = y + dy[d];
                int tx = x + dx[d];
                
                if (0 <= ty && ty < a.size() && 0 <= tx && tx < a[0].size() && a[ty][tx] == "." && dist[ty][tx] > dist[y][x] + 1) {
                    dist[ty][tx] = dist[y][x] + 1;
                    q.push({ ty, tx });
                }
            }
        }
        
        return dist;
    }

public:
    int minimumSeconds(vector<vector<string>> &a) {
        vector<pair<int, int>> start1, start2;
        int finishY, finishX;

        for (int y = 0; y < a.size(); y++) {
            for (int x = 0; x < a[0].size(); x++) {
                if (a[y][x] == "S") {
                    start1.push_back({ y, x });
                } else if (a[y][x] == "*") {
                    start2.push_back({ y, x });
                } else if (a[y][x] == "D") {
                    finishY = y;
                    finishX = x;
                }
            }
        }

        vector<vector<int>> dist1 = bfs(a, start1);
        vector<vector<int>> dist2 = bfs(a, start2);

        int res = 1e9;
        for (int d = 0; d < dy.size(); d++) {
            int ty = finishY + dy[d];
            int tx = finishX + dx[d];
            
            if (0 <= ty && ty < a.size() && 0 <= tx && tx < a[0].size() && dist1[ty][tx] < dist2[ty][tx])
                res = min(res, dist1[ty][tx] + 1);
        }
        return res != 1e9 ? res : -1;
    }
};