class Solution {
    void dfs(vector<vector<pair<int, int>>> &graph, int v, int p, string &a, string &b, vector<int> &res) {
        for (auto &[to, i] : graph[v]) {
            if (to == p)
                continue;
            
            dfs(graph, to, v, a, b, res);

            if (a[to] != b[to]) {
                a[v] ^= 1;
                a[to] ^= 1;
                res.push_back(i);
            }
        }
    }

public:
    vector<int> minimumFlips(int vertexCount, vector<vector<int>> &edges, string &a, string &b) {
        vector<vector<pair<int, int>>> graph(vertexCount);
        for (int i = 0; i < edges.size(); i++) {
            graph[edges[i][0]].push_back({ edges[i][1], i });
            graph[edges[i][1]].push_back({ edges[i][0], i });
        }

        vector<int> res;
        dfs(graph, 0, -1, a, b, res);

        if (a == b) {
            sort(res.begin(), res.end());
            return res;
        } else {
            return { -1 };
        }
    }
};