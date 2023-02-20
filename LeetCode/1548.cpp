class Solution {
public:
    vector<int> mostSimilar(int vertexCount, vector<vector<int>> &edges, vector<string> &names, vector<string> &targetPath) {
        vector<vector<int>> graph(vertexCount);
        for (vector<int> &edge : edges) {
            graph[edge[0]].push_back(edge[1]);
            graph[edge[1]].push_back(edge[0]);
        }

        vector<vector<int>> cost(targetPath.size(), vector<int>(vertexCount, 1e9));
        vector<vector<int>> from(targetPath.size(), vector<int>(vertexCount));

        for (int v = 0; v < vertexCount; v++)
            cost[0][v] = names[v] != targetPath[0];
        
        for (int i = 1; i < targetPath.size(); i++) {
            for (int last = 0; last < vertexCount; last++) {
                for (int prev : graph[last]) {
                    int candidateCost = cost[i - 1][prev] + (names[last] != targetPath[i]);
                    if (cost[i][last] > candidateCost) {
                        cost[i][last] = candidateCost;
                        from[i][last] = prev;
                    }
                }
            }
        }

        vector<int> path(targetPath.size());        
        int last = min_element(cost.back().begin(), cost.back().end()) - cost.back().begin();
        for (int i = targetPath.size() - 1; i >= 0; i--) {
            path[i] = last;
            last = from[i][last];
        }
        return path;
    }
};
