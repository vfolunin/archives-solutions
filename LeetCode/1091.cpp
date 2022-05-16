class Solution {
    int bfs(vector<vector<int>> &a) {
        if (a[0][0])
            return -1;
        
        int n = a.size();
        
        vector<vector<int>> dist(n, vector<int>(n, -1));
        queue<int> q;
        
        dist[0][0] = 1;
        q.push(0);
        q.push(0);
        
        while (!q.empty()) {
            int y = q.front();
            q.pop();
            int x = q.front();
            q.pop();
            
            static vector<int> dy = { -1, -1, -1, 0, 1, 1, 1, 0 };
            static vector<int> dx = { -1, 0, 1, 1, 1, 0, -1, -1 };
            
            for (int d = 0; d < dy.size(); d++) {
                int ty = y + dy[d], tx = x + dx[d];
                if (0 <= ty && ty < n && 0 <= tx && tx < n && !a[ty][tx] && dist[ty][tx] == -1) {
                    dist[ty][tx] = dist[y][x] + 1;
                    q.push(ty);
                    q.push(tx);
                }
            }
        }
        
        return dist[n - 1][n - 1];
    }
public:
    int shortestPathBinaryMatrix(vector<vector<int>> &a) {
        return bfs(a);
    }
};