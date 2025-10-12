class Solution {
    void dfs(vector<vector<int>> &graph, int v, int p, vector<int> &a, map<vector<int>, int> &count, long long &res) {
        vector<int> divisors;
        for (int d = 2; d * d <= a[v]; d++) {
            if (a[v] % d)
                continue;

            int p = 0;
            while (a[v] % d == 0) {
                a[v] /= d;
                p ^= 1;
            }

            if (p)
                divisors.push_back(d);
        }
        if (a[v] > 1)
            divisors.push_back(a[v]);
        
        res += count[divisors];
        count[divisors]++;

        for (int to : graph[v])
            if (to != p)
                dfs(graph, to, v, a, count, res);
        
        if (!--count[divisors])
            count.erase(divisors);
    }

public:
    long long sumOfAncestors(int vertexCount, vector<vector<int>> &edges, vector<int> &a) {
        vector<vector<int>> graph(vertexCount);
        for (vector<int> &edge : edges) {
            graph[edge[0]].push_back(edge[1]);
            graph[edge[1]].push_back(edge[0]);
        }

        map<vector<int>, int> count;
        long long res = 0;
        dfs(graph, 0, -1, a, count, res);
        return res;
    }
};