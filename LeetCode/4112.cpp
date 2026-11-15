class Solution {
    int dfs(vector<vector<int>> &graph, int v, vector<int> &op, vector<int> &score) {
        int sum = score[v];
        int minScore = 1e9;
        for (int to : graph[v]) {
            int toScore = dfs(graph, to, op, score);
            sum += toScore;
            minScore = min(minScore, toScore);
        }
        if (minScore != 1e9 && (op[v] == 1 || minScore < 0))
            sum -= minScore;
        return sum;
    }

public:
    int maxScore(vector<int> &parent, vector<int> &op, vector<int> &score) {
        vector<vector<int>> graph(parent.size());
        for (int v = 1; v < graph.size(); v++)
            graph[parent[v]].push_back(v);
        
        return dfs(graph, 0, op, score);
    }
};