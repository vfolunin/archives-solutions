class Solution {
    void dfs(vector<vector<int>> &graph, int v, vector<int> &from) {
        for (int to : graph[v]) {
            if (to != from[v]) {
                from[to] = v;
                dfs(graph, to, from);
            }
        }
    }

    void updateCount(vector<vector<int>> &graph, int start, int finish, vector<int> &count) {
        vector<int> from(graph.size(), -1);
        dfs(graph, start, from);
        for (int v = finish; v != -1; v = from[v])
            count[v]++;
    }

    void rec(vector<vector<int>> &graph, int v, int p, vector<int> &count, vector<int> &price, vector<vector<int>> &cost) {
        cost[v][0] = count[v] * price[v];
        cost[v][1] = count[v] * price[v] / 2;

        for (int to : graph[v]) {
            if (to != p) {
                rec(graph, to, v, count, price, cost);
                cost[v][0] += min(cost[to][0], cost[to][1]);
                cost[v][1] += cost[to][0];
            }
        }
    }

public:
    int minimumTotalPrice(int vertexCount, vector<vector<int>> &edges, vector<int> &price, vector<vector<int>> &trips) {
        vector<vector<int>> graph(vertexCount);
        for (vector<int> &edge : edges) {
            graph[edge[0]].push_back(edge[1]);
            graph[edge[1]].push_back(edge[0]);
        }

        vector<int> count(vertexCount);
        for (vector<int> &trip : trips)
            updateCount(graph, trip[0], trip[1], count);
        
        vector<vector<int>> cost(vertexCount, vector<int>(2));
        rec(graph, 0, -1, count, price, cost);
        return min(cost[0][0], cost[0][1]);
    }
};