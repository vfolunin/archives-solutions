class Solution {
    vector<long long> dijkstra(vector<vector<pair<int, int>>> &graph, int power, vector<int> &cost, int start, int finish) {
        vector<vector<long long>> dist(graph.size(), vector<long long>(power + 1, 1e18));
        priority_queue<tuple<long long, int, int>> q;

        dist[start][power] = 0;
        q.push({ dist[start][power], start, power });

        while (!q.empty()) {
            auto [d, v, p] = q.top();
            q.pop();

            if (-d != dist[v][p] || p < cost[v])
                continue;
            int toP = p - cost[v];
            
            for (auto &[to, weight] : graph[v]) {
                if (dist[to][toP] > dist[v][p] + weight) {
                    dist[to][toP] = dist[v][p] + weight;
                    q.push({ -dist[to][toP], to, toP });
                }
            }
        }

        long long minDist = *min_element(dist[finish].begin(), dist[finish].end());
        if (minDist == 1e18)
            return { -1, -1 };
        
        long long maxP = power;
        while (dist[finish][maxP] != minDist)
            maxP--;
        return { minDist, maxP };
    }

public:
    vector<long long> minTimeMaxPower(int vertexCount, vector<vector<int>> &edges, int power, vector<int> &cost, int start, int finish) {
        vector<vector<pair<int, int>>> graph(vertexCount);
        for (vector<int> &edge : edges)
            graph[edge[0]].push_back({ edge[1], edge[2] });

        return dijkstra(graph, power, cost, start, finish);
    }
};