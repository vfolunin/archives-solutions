class Solution {
    void dfs1(vector<vector<int>> &graph, int v, int p, vector<vector<int>> &distDown) {
        distDown[v].resize(2);

        for (int to : graph[v]) {
            if (to == p)
                continue;
            
            dfs1(graph, to, v, distDown);

            int dist = distDown[to][0] + (to % 2 ? 1 : 2);
            if (dist >= distDown[v][0])
                distDown[v] = { dist, distDown[v][0] };
            else if (dist > distDown[v][1])
                distDown[v][1] = dist;
        }        
    }

    void dfs2(vector<vector<int>> &graph, int v, int p, vector<vector<int>> &distDown, int distUp, vector<int> &res) {
        for (int to : graph[v]) {
            if (to == p)
                continue;
            
            int toDistDown = distDown[to][0] + (to % 2 ? 1 : 2);
            int otherDistDown = distDown[v][toDistDown == distDown[v][0]];
            int toDistUp = max(distUp, otherDistDown) + (v % 2 ? 1 : 2);

            dfs2(graph, to, v, distDown, toDistUp, res);
        }

        res[v] = max(distDown[v][0], distUp);
    }

public:
    vector<int> timeTaken(vector<vector<int>> &edges) {
        vector<vector<int>> graph(edges.size() + 1);
        for (vector<int> &edge : edges) {
            graph[edge[0]].push_back(edge[1]);
            graph[edge[1]].push_back(edge[0]);
        }

        vector<vector<int>> distDown(graph.size());
        dfs1(graph, 0, -1, distDown);

        vector<int> res(graph.size());
        dfs2(graph, 0, -1, distDown, 0, res);
        return res;
    }
};