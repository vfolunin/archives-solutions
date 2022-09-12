class Solution {
    int bfs(vector<vector<int>> &a) {
        int h = a.size(), w = a[0].size();
        
        map<vector<vector<int>>, int> dist;
        queue<vector<vector<int>>> q;
        
        dist[a] = 0;
        q.push(a);
        
        while (!q.empty()) {
            vector<vector<int>> v = q.front();
            q.pop();
            
            if (v == vector<vector<int>> { { 1, 2, 3 }, { 4, 5, 0 } })
                return dist[v];
            
            int y, x;
            for (int i = 0; i < 6; i++) {
                if (!v[i / 3][i % 3]) {
                    y = i / 3;
                    x = i % 3;
                    break;
                }
            }                
            
            static vector<int> dy = { -1, 0, 1, 0 };
            static vector<int> dx = { 0, 1, 0, -1 };
            
            for (int d = 0; d < dy.size(); d++) {
                int ty = y + dy[d];
                int tx = x + dx[d];
                
                if (0 <= ty && ty < 2 && 0 <= tx && tx < 3) {
                    vector<vector<int>> to = v;
                    swap(to[y][x], to[ty][tx]);
                    
                    if (!dist.count(to)) {
                        dist[to] = dist[v] + 1;
                        q.push(to);
                    }
                }
            }
        }
        
        return -1;
    }
    
public:
    int slidingPuzzle(vector<vector<int>> &a) {
        return bfs(a);
    }
};