class Solution {
    int rec(vector<vector<int>> &graph, string &s, int va, int vb, int mask, vector<vector<vector<int>>> &memo) {
        int &res = memo[va][vb][mask];
        if (res != -1)
            return res;

        res = 1 + (va != vb);
        
        for (int toA : graph[va]) {
            if (mask & (1 << toA))
                continue;
            for (int toB : graph[vb]) {
                if ((mask & (1 << toB)) || toA == toB || s[toA] != s[toB])
                    continue;
                res = max(res, rec(graph, s, toA, toB, mask | (1 << toA) | (1 << toB), memo) + 1 + (va != vb));
            }
        }

        return res;
    }

public:
    int maxLen(int vertexCount, vector<vector<int>> &edges, string &s) {
        vector<vector<int>> graph(vertexCount);
        for (vector<int> &edge : edges) {
            graph[edge[0]].push_back(edge[1]);
            graph[edge[1]].push_back(edge[0]);
        }

        vector memo(vertexCount, vector(vertexCount, vector<int>(1 << vertexCount, -1)));
        int res = 0;

        for (int v = 0; v < vertexCount; v++)
            res = max(res, rec(graph, s, v, v, 1 << v, memo));
        
        for (int va = 0; va < vertexCount; va++)
            for (int vb : graph[va])
                if (s[va] == s[vb])
                    res = max(res, rec(graph, s, va, vb, (1 << va) | (1 << vb), memo));
        
        return res;
    }
};