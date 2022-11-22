class Solution {
    bool dfs(int y, int x, int targetY, int targetX, set<pair<int, int>> &visited, set<pair<int, int>> &blocked) {
        if (y == targetY && x == targetX)
            return 1;
        
        visited.insert({ y, x });
        if (visited.size() > 3e4)
            return 1;

        static vector<int> dy = { -1, 0, 1, 0 };
        static vector<int> dx = { 0, 1, 0, -1 };

        for (int d = 0; d < dy.size(); d++) {
            int ty = y + dy[d];
            int tx = x + dx[d];

            if (0 <= ty && ty < 1e6 && 0 <= tx && tx < 1e6 &&
                !visited.count({ ty, tx }) && !blocked.count({ ty, tx }) &&
                dfs(ty, tx, targetY, targetX, visited, blocked))
                return 1;
        }

        return 0;
    }
    
public:
    bool isEscapePossible(vector<vector<int>> &blockedArr, vector<int> &start, vector<int> &finish) {
        set<pair<int, int>> blocked, visitedStart, visitedFinish;
        for (vector<int> &cell : blockedArr)
            blocked.insert({ cell[0], cell[1] });
        
        return dfs(start[0], start[1], finish[0], finish[1], visitedStart, blocked) && 
               dfs(finish[0], finish[1], start[0], start[1], visitedFinish, blocked);
    }
};