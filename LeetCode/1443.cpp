class Solution {
    int rec(vector<vector<int>> &graph, int v, int p, vector<bool> &hasApple) {
        int res = 0;
        for (int to : graph[v]) {
            if (to == p)
                continue;
            int toRes = rec(graph, to, v, hasApple);
            if (toRes || hasApple[to])
                res += 2 + toRes;
        }
        return res;
    }
    
public:
    int minTime(int vertexCount, vector<vector<int>> &edges, vector<bool> &hasApple) {
        vector<vector<int>> graph(vertexCount);
        for (vector<int> &edge : edges) {
            graph[edge[0]].push_back(edge[1]);
            graph[edge[1]].push_back(edge[0]);
        }
        return rec(graph, 0, -1, hasApple);
    }
};