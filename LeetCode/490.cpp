class Solution {
    int bfs(vector<vector<int>> &a, int startY, int startX, int finishY, int finishX) {
        vector<vector<int>> dist(a.size(), vector<int>(a[0].size(), 1e9));
        queue<pair<int, int>> q;
        
        dist[startY][startX] = 0;
        q.push({ startY, startX });
        
        vector<int> dy = { -1, 0, 1, 0 };
        vector<int> dx = { 0, 1, 0, -1 };
        
        while (!q.empty()) {
            auto [y, x] = q.front();
            q.pop();
                
            for (int d = 0; d < dy.size(); d++) {
                int step = 0;
                while (1) {
                    int ty = y + dy[d] * (step + 1);
                    int tx = x + dx[d] * (step + 1);

                    if (0 <= ty && ty < a.size() && 0 <= tx && tx < a[0].size() && !a[ty][tx])
                        step++;
                    else
                        break;
                }

                int ty = y + dy[d] * step;
                int tx = x + dx[d] * step;
            
                if (dist[ty][tx] == 1e9) {
                    dist[ty][tx] = dist[y][x] + 1;
                    q.push({ ty, tx });
                }
            }
        }
        
        return dist[finishY][finishX];
    }

public:
    bool hasPath(vector<vector<int>> &a, vector<int> &start, vector<int> &finish) {
        return bfs(a, start[0], start[1], finish[0], finish[1]) != 1e9;
    }
};