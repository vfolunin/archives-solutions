class Solution {
    int rec(vector<vector<int>> &graph, int v, int p, vector<int> &a, vector<int> &xors) {
        int res = a[v];
        for (int to : graph[v])
            if (to != p)
                res ^= rec(graph, to, v, a, xors);
        xors.push_back(res);
        return res;
    }
    
public:
    int minimumScore(vector<int> &a, vector<vector<int>> &edges) {
        vector<vector<int>> graph(a.size());
        for (vector<int> &edge : edges) {
            graph[edge[0]].push_back(edge[1]);
            graph[edge[1]].push_back(edge[0]);
        }
               
        int res = 1e9;
        for (vector<int> &edge : edges) {
            vector<int> xors0, xors1;
            rec(graph, edge[0], edge[1], a, xors0);
            rec(graph, edge[1], edge[0], a, xors1);
            
            for (int i = 0; i + 1 < xors0.size(); i++) {
                int a = xors0[i], b = xors0.back() ^ xors0[i], c = xors1.back();
                res = min(res, max({ a, b, c }) - min({ a, b, c }));
            }
            
            for (int i = 0; i + 1 < xors1.size(); i++) {
                int a = xors1[i], b = xors1.back() ^ xors1[i], c = xors0.back();
                res = min(res, max({ a, b, c }) - min({ a, b, c }));
            }
        }
        return res;
    }
};