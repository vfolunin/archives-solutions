class Solution {
public:
    int maxConsistentColumns(vector<vector<int>> &a, int limit) {
        vector<vector<int>> graph(a[0].size());
        for (int x = 0; x < a[0].size(); x++) {
            for (int toX = x + 1; toX < a[0].size(); toX++) {
                bool ok = 1;
                for (int y = 0; y < a.size() && ok; y++)
                    ok &= abs(a[y][x] - a[y][toX]) <= limit;
                if (ok)
                    graph[x].push_back(toX);
            }
        }

        vector<int> maxDist(graph.size(), 1);
        for (int v = graph.size() - 1; v >= 0; v--)
            for (int to : graph[v])
                maxDist[v] = max(maxDist[v], maxDist[to] + 1);
        return *max_element(maxDist.begin(), maxDist.end());
    }
};