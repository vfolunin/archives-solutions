class Solution {
    struct Data {
        long long size, allBlue, redRoot, blueRoot;
    };

    Data dfs(vector<vector<int>> &graph, int v, int parent, string &color) {
        Data vData = { 1, 0, 0, 0 };

        long long blueToRed = 1e18;
        for (int to : graph[v]) {
            if (to != parent) {
                Data toData = dfs(graph, to, v, color);
                vData.size += toData.size;
                vData.allBlue += toData.allBlue;
                vData.redRoot += min(toData.allBlue, toData.redRoot);
                blueToRed = min(blueToRed, min(toData.redRoot, toData.blueRoot) - toData.allBlue);
            }
        }
        
        if (color[v] == 'R')
            vData.allBlue += vData.size;
        else
            vData.redRoot += vData.size;
        vData.blueRoot = vData.allBlue + blueToRed;

        return vData;
    }

public:
    long long minCost(int vertexCount, string &color, vector<vector<int>> &edges) {
        vector<vector<int>> graph(vertexCount);
        for (vector<int> &edge : edges) {
            graph[edge[0]].push_back(edge[1]);
            graph[edge[1]].push_back(edge[0]);
        }
        Data data = dfs(graph, 0, -1, color);
        return min({ data.allBlue, data.redRoot, data.blueRoot });
    }
};