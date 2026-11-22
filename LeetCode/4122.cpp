class Solution {
public:
    vector<long long> earliestActivationTimes(int vertexCount, vector<vector<int>> &edges, vector<int> &threshold) {
        threshold[0] = -1;

        vector<vector<pair<int, int>>> graph(vertexCount);
        for (vector<int> &edge : edges)
            graph[edge[0]].push_back({ edge[1], edge[2] });

        vector<multiset<long long>> dists(graph.size());
        vector<long long> dist(graph.size(), 1e18);
        set<pair<long long, int>> q;

        dist[0] = 0;
        q.insert({ dist[0], 0 });

        while (!q.empty()) {
            int v = q.begin()->second;
            q.erase(q.begin());

            for (auto &[to, weight] : graph[v]) {
                dists[to].insert(dist[v] + weight);
                if (dists[to].size() > threshold[to])
                    dists[to].erase(prev(dists[to].end()));
                
                if (dists[to].size() == threshold[to] && dist[to] > *prev(dists[to].end())) {
                    q.erase({ dist[to], to });
                    dist[to] = *prev(dists[to].end());
                    q.insert({ dist[to], to });
                }
            }
        }

        for (long long &value : dist)
            if (value == 1e18)
                value = -1;

        return dist;
    }
};