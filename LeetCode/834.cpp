class Solution {
    void dfs1(vector<vector<int>> &graph, int v, int p, vector<int> &size, vector<int> &distSum) {
        size[v] = 1;
        
        for (int to : graph[v]) {
            if (to == p)
                continue;
            
            dfs1(graph, to, v, size, distSum);
            
            size[v] += size[to];
            distSum[v] += distSum[to] + size[to];
        }
    }
    
    void dfs2(vector<vector<int>> &graph, int v, int p, vector<int> &size, vector<int> &distSum) {
        for (int to : graph[v]) {
            if (to == p)
                continue;
            
            distSum[to] = distSum[v] + graph.size() - 2 * size[to];
            
            dfs2(graph, to, v, size, distSum);
        }
    }
    
public:
    vector<int> sumOfDistancesInTree(int vertexCount, vector<vector<int>> &edges) {
        vector<vector<int>> graph(vertexCount);
        for (vector<int> &edge : edges) {
            graph[edge[0]].push_back(edge[1]);
            graph[edge[1]].push_back(edge[0]);
        }
        
        vector<int> size(vertexCount), distSum(vertexCount);
        dfs1(graph, 0, -1, size, distSum);
        dfs2(graph, 0, -1, size, distSum);
        return distSum;
    }
};