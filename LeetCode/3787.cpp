class Solution {
    vector<int> bfs(vector<vector<int>> &graph, const vector<int> &starts) {
        vector<int> dist(graph.size(), 1e9);
        queue<int> q;

        for (int start : starts) {
            dist[start] = 0;
            q.push(start);
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
    string findSpecialNodes(int vertexCount, vector<vector<int>> &edges) {
        vector<vector<int>> graph(vertexCount);
        for (vector<int> &edge : edges) {
            graph[edge[0]].push_back(edge[1]);
            graph[edge[1]].push_back(edge[0]);
        }
        
        vector<int> dist = bfs(graph, { 0 });
        dist = bfs(graph, { (int)(max_element(dist.begin(), dist.end()) - dist.begin()) });

        int diameter = *max_element(dist.begin(), dist.end());
        vector<int> starts;
        string res(vertexCount, '0');
        for (int v = 0; v < vertexCount; v++) {
            if (dist[v] == diameter) {
                starts.push_back(v);
                res[v] = '1';
            }
        }
        
        dist = bfs(graph, starts);
        for (int v = 0; v < vertexCount; v++)
            if (dist[v] == diameter)
                res[v] = '1';
        return res;
    }
};