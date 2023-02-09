class Solution {
    void dfs(vector<vector<int>> &graph, int v, vector<int> &visited, vector<int> &from, vector<int> &cycle) {
        visited[v] = 1;
        for (int to : graph[v]) {
            if (to == from[v]) {
                continue;
            } else if (!visited[to]) {
                from[to] = v;
                dfs(graph, to, visited, from, cycle);
            } else if (visited[to] == 1 && cycle.empty()) {
                cycle.push_back(to);
                for (int cycleV = v; cycleV != to; cycleV = from[cycleV]) 
                    cycle.push_back(cycleV);
            }   
        }        
        visited[v] = 2;
    }

    vector<int> bfs(vector<vector<int>> &graph, vector<int> &start) {
        vector<int> dist(graph.size(), 1e9);
        queue<int> q;

        for (int v : start) {
            dist[v] = 0;
            q.push(v);
        }

        while (!q.empty()) {
            int v = q.front();
            q.pop();

            for (int to : graph[v]) {
                if (dist[to] > dist[v] + 1) {
                    dist[to] = dist[v] + 1;
                    q.push(to);
                }
            }
        }

        return dist;
    }

public:
    vector<int> distanceToCycle(int vertexCount, vector<vector<int>> &edges) {
        vector<vector<int>> graph(vertexCount);
        for (vector<int> &edge : edges) {
            graph[edge[0]].push_back(edge[1]);
            graph[edge[1]].push_back(edge[0]);
        }

        vector<int> visited(vertexCount), from(vertexCount, -1), cycle;
        dfs(graph, 0, visited, from, cycle);
        return bfs(graph, cycle);
    }
};