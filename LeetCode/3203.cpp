class Solution {
    vector<int> bfs(vector<vector<int>> &graph, const int start) {
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

    int getDiameter(vector<vector<int>> &edges) {
        vector<vector<int>> graph(edges.size() + 1);
        for (vector<int> &edge : edges) {
            graph[edge[0]].push_back(edge[1]);
            graph[edge[1]].push_back(edge[0]);
        }
        
        vector<int> dist = bfs(graph, 0);
        int a = max_element(dist.begin(), dist.end()) - dist.begin();

        vector<int> distA = bfs(graph, a);
        return *max_element(distA.begin(), distA.end());
    }

public:
    int minimumDiameterAfterMerge(vector<vector<int>> &edges1, vector<vector<int>> &edges2) {
        int d1 = getDiameter(edges1);
        int d2 = getDiameter(edges2);
        return max({ d1, d2, (d1 + 1) / 2 + (d2 + 1) / 2 + 1 });
    }
};