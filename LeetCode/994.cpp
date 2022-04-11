class Solution {
public:
    int orangesRotting(vector<vector<int>> &a) {
        vector<vector<int>> dist(a.size(), vector<int>(a[0].size(), 1e9));
        queue<int> q;
        
        for (int y = 0; y < a.size(); y++) {
            for (int x = 0; x < a[y].size(); x++) {
                if (a[y][x] == 2) {
                    dist[y][x] = 0;
                    q.push(y);
                    q.push(x);
                }
            }
        }
        
        while (!q.empty()) {
            int y = q.front();
            q.pop();
            int x = q.front();
            q.pop();
            
            static int dy[] = { -1, 0, 1, 0 };
            static int dx[] = { 0, 1, 0, -1 };
            
            for (int d = 0; d < 4; d++) {
                int ty = y + dy[d], tx = x + dx[d];
                if (0 <= ty && ty < a.size() && 0 <= tx && tx < a[ty].size() && a[ty][tx] == 1) {
                    a[ty][tx] = 3;
                    dist[ty][tx] = dist[y][x] + 1;
                    q.push(ty);
                    q.push(tx);
                }
            }
        }
        
        int maxDist = 0;
        for (int y = 0; y < a.size(); y++) {
            for (int x = 0; x < a[y].size(); x++) {
                if (a[y][x] == 1)
                    return -1;
                if (a[y][x] == 3)
                    maxDist = max(maxDist, dist[y][x]);
            }
        }        
        return maxDist;
    }
};