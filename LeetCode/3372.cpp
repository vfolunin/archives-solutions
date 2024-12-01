class Solution {
    vector<int> bfs(vector<vector<int>> &graph, int start) {
        vector<int> dist(graph.size(), 1e9);
        queue<int> q;

        dist[start] = 0;
        q.push(start);

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
    vector<int> maxTargetNodes(vector<vector<int>> &edges1, vector<vector<int>> &edges2, int limit) {
        vector<vector<int>> graph1(edges1.size() + 1);
        for (vector<int> &edge : edges1) {
            graph1[edge[0]].push_back(edge[1]);
            graph1[edge[1]].push_back(edge[0]);
        }
        
        vector<vector<int>> graph2(edges2.size() + 1);
        for (vector<int> &edge : edges2) {
            graph2[edge[0]].push_back(edge[1]);
            graph2[edge[1]].push_back(edge[0]);
        }

        int count2 = 0;
        for (int v = 0; v < graph2.size(); v++) {
            vector<int> dist = bfs(graph2, v);
            count2 = max<int>(count2, count_if(dist.begin(), dist.end(), [&](int d) {
                return d <= limit - 1;
            }));
        }

        vector<int> res(graph1.size());
        for (int v = 0; v < graph1.size(); v++) {
            vector<int> dist = bfs(graph1, v);
            res[v] = count_if(dist.begin(), dist.end(), [&](int d) {
                return d <= limit;
            }) + count2;
        }
        return res;
    }
};