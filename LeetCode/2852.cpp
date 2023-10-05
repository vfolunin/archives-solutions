class Solution {
    long long dfs(vector<vector<int>> &a, int y, int x, vector<vector<int>> &visited, int component) {
        visited[y][x] = component;
        long long res = a[y][x];
        
        static vector<int> dy = { -1, 0, 1, 0 };
        static vector<int> dx = { 0, 1, 0, -1 };
        
        for (int d = 0; d < dy.size(); d++) {
            int ty = y + dy[d];
            int tx = x + dx[d];
            
            if (0 <= ty && ty < a.size() && 0 <= tx && tx < a[0].size() && a[ty][tx] != -1 && visited[ty][tx] == -1)
                res += dfs(a, ty, tx, visited, component);
        }

        return res;
    }

public:
    long long sumRemoteness(vector<vector<int>> &a) {
        vector<vector<int>> visited(a.size(), vector<int>(a.size(), -1));
        vector<long long> componentSum;
        long long totalSum = 0;

        for (int y = 0; y < a.size(); y++) {
            for (int x = 0; x < a.size(); x++) {
                if (a[y][x] != -1) {
                    if (visited[y][x] == -1)
                        componentSum.push_back(dfs(a, y, x, visited, componentSum.size()));
                    totalSum += a[y][x];
                }
            }
        }

        long long res = 0;
        for (int y = 0; y < a.size(); y++)
            for (int x = 0; x < a.size(); x++)
                if (a[y][x] != -1)
                    res += totalSum - componentSum[visited[y][x]];
        return res;
    }
};