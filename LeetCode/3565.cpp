class Solution {
    bool rec(vector<vector<int>> &a, int y, int x, int target, vector<vector<int>> &visited, vector<vector<int>> &path) {
        visited[y][x] = 1;
        path.push_back({ y, x });

        if (path.size() == a.size() * a[0].size())
            return 1;
        
        static const vector<int> dy = { -1, 0, 1, 0 };
        static const vector<int> dx = { 0, 1, 0, -1 };

        for (int d = 0; d < dy.size(); d++) {
            int ty = y + dy[d];
            int tx = x + dx[d];

            if (0 <= ty && ty < a.size() && 0 <= tx && tx < a[0].size() &&
                !visited[ty][tx] && (!a[ty][tx] || a[ty][tx] == target) &&
                rec(a, ty, tx, target + (a[ty][tx] == target), visited, path))
                    return 1;
        }

        path.pop_back();
        visited[y][x] = 0;

        return 0;
    }

public:
    vector<vector<int>> findPath(vector<vector<int>> &a, int size) {
        vector<vector<int>> visited(a.size(), vector<int>(a[0].size()));
        vector<vector<int>> path;

        for (int y = 0; y < a.size(); y++)
            for (int x = 0; x < a[0].size(); x++)
                if (a[y][x] <= 1 && rec(a, y, x, 1 + (a[y][x] == 1), visited, path))
                    return path;
                    
        return {};
    }
};