class Solution {
public:
    void rec(vector<vector<int>> &graph, int v, int pBuy, vector<int> &a, vector<int> &b, vector<vector<vector<int>>> &memo) {
        vector<int> &res = memo[v][pBuy];
        if (res[0] != -1)
            return;

        int price = pBuy ? a[v] / 2 : a[v], profit = b[v] - price;

        vector<vector<int>> maxProfit(2, vector<int>(res.size()));
        for (int to : graph[v]) {
            for (int buy : { 0, 1 }) {
                rec(graph, to, buy, a, b, memo);
                for (int limit = res.size() - 1; limit >= 0; limit--)
                    for (int toLimit = 0; toLimit <= limit; toLimit++)
                        maxProfit[buy][limit] = max(maxProfit[buy][limit], maxProfit[buy][limit - toLimit] + memo[to][buy][toLimit]);
            }
        }

        for (int limit = 0; limit < res.size(); limit++) {
            res[limit] = max(res[limit], maxProfit[0][limit]);
            if (limit >= price)
                res[limit] = max(res[limit], maxProfit[1][limit - price] + profit);
        }
    }

    int maxProfit(int vertexCount, vector<int> &a, vector<int> &b, vector<vector<int>> &edges, int limit) {
        vector<vector<int>> graph(vertexCount);
        for (vector<int> &edge : edges)
            graph[edge[0] - 1].push_back(edge[1] - 1);

        vector memo(vertexCount, vector(2, vector<int>(limit + 1, -1)));
        rec(graph, 0, 0, a, b, memo);
        return memo[0][0][limit];
    }
};