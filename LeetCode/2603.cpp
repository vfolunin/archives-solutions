class Solution {
public:
    int collectTheCoins(vector<int> &coins, vector<vector<int>> &edges) {
        int vertexCount = edges.size() + 1;
        unordered_map<int, unordered_set<int>> graph;

        for (vector<int> &edge : edges) {
            graph[edge[0]].insert(edge[1]);
            graph[edge[1]].insert(edge[0]);
        }

        queue<int> leaves;
        for (int v = 0; v < vertexCount; v++)
            if (!coins[v] && graph[v].size() == 1)
                leaves.push(v);

        while (!leaves.empty()) {
            int v = leaves.front();
            leaves.pop();

            for (int to : graph[v]) {
                graph[to].erase(v);
                if (!coins[to] && graph[to].size() == 1)
                    leaves.push(to);
            }

            graph.erase(v);
        }

        for (int i = 0; i < 2; i++) {
            queue<int> leaves;
            for (int v = 0; v < vertexCount; v++)
                if (graph.count(v) && graph[v].size() == 1)
                    leaves.push(v);

            while (!leaves.empty()) {
                int v = leaves.front();
                leaves.pop();

                for (int to : graph[v])
                    graph[to].erase(v);
                    
                graph.erase(v);
            }
        }
        
        if (!graph.empty())
            return (graph.size() - 1) * 2;
        else
            return 0;
    }
};