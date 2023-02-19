class Solution {
public:
    int maxVacationDays(vector<vector<int>> &hasEdge, vector<vector<int>> &bonus) {
        int vertexCount = bonus.size(), weekCount = bonus[0].size();

        vector<vector<int>> res(weekCount + 1, vector<int>(vertexCount, -1e9));
        res[0][0] = 0;

        for (int week = 0; week < weekCount; week++) {
            for (int v = 0; v < vertexCount; v++) {
                if (res[week][v] == -1e9)
                    continue;
                
                for (int to = 0; to < vertexCount; to++)
                    if (v == to || hasEdge[v][to])
                        res[week + 1][to] = max(res[week + 1][to], res[week][v] + bonus[to][week]);
            }
        }

        return *max_element(res.back().begin(), res.back().end());
    }
};