class Solution {
public:
    int minTrioDegree(int vertexCount, vector<vector<int>> &edges) {
        vector<int> degree(vertexCount);
        vector<vector<int>> graph(vertexCount), hasEdge(vertexCount, vector<int>(vertexCount));
        
        for (vector<int> &edge : edges) {
            int a = edge[0] - 1, b = edge[1] - 1;
            if (a > b)
                swap(a, b);
            degree[a]++;
            degree[b]++;
            graph[a].push_back(b);
            hasEdge[a][b] = hasEdge[b][a] = 1;
        }
        
        int res = 1e9;
        for (int v = 0; v < vertexCount; v++)
            for (int i = 0; i < graph[v].size(); i++)
                for (int j = i + 1; j < graph[v].size(); j++)
                    if (hasEdge[graph[v][i]][graph[v][j]])
                        res = min(res, degree[v] + degree[graph[v][i]] + degree[graph[v][j]] - 6);
        return res != 1e9 ? res : -1;
    }
};