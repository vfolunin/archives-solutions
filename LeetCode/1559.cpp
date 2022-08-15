class Solution {
    void dfs(vector<vector<char>> &a, int y, int x, int py, int px, vector<vector<int>> &visited, bool &hasCycle) {
        visited[y][x] = 1;
        
        static vector<int> dy = { -1, 0, 1, 0 };
        static vector<int> dx = { 0, 1, 0, -1 };
        
        for (int d = 0; d < dy.size(); d++) {
            int ty = y + dy[d];
            int tx = x + dx[d];
            
            if (0 <= ty && ty < a.size() && 0 <= tx && tx < a[0].size() && (ty != py || tx != px) && a[ty][tx] == a[y][x]) {
                if (visited[ty][tx] == 0)
                    dfs(a, ty, tx, y, x, visited, hasCycle);
                else if (visited[ty][tx] == 1)
                    hasCycle = 1;
            }
        }
        
        visited[y][x] = 2;
    }
    
public:
    bool containsCycle(vector<vector<char>> &a) {
        vector<vector<int>> visited(a.size(), vector<int>(a[0].size()));
        bool hasCycle = 0;
        
        for (int y = 0; !hasCycle && y < a.size(); y++)
            for (int x = 0; !hasCycle && x < a[0].size(); x++)
                if (!visited[y][x]) 
                    dfs(a, y, x, -1, -1, visited, hasCycle);
        
        return hasCycle;
    }
};