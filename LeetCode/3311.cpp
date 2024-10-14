class Solution {
    int getDegree(vector<vector<int>> &graph, vector<int> &visited, int v) {
        int res = 0;
        for (int to : graph[v])
            res += !visited[to];
        return res;
    }

    int getBestTo(vector<vector<int>> &graph, vector<int> &visited, int v = -1) {
        int bestTo = -1;
        if (v == -1) {
            for (int to = 0; to < graph.size(); to++)
                if (!visited[to] && (bestTo == -1 || getDegree(graph, visited, bestTo) > getDegree(graph, visited, to)))
                    bestTo = to;
        } else {
            for (int to : graph[v])
                if (!visited[to] && (bestTo == -1 || getDegree(graph, visited, bestTo) > getDegree(graph, visited, to)))
                    bestTo = to;
        }
        if (bestTo != -1)
            visited[bestTo] = 1;
        return bestTo;
    }

public:
    vector<vector<int>> constructGridLayout(int vertexCount, vector<vector<int>> &edges) {
        vector<vector<int>> graph(vertexCount);
        for (vector<int> &edge : edges) {
            graph[edge[0]].push_back(edge[1]);
            graph[edge[1]].push_back(edge[0]);
        }

        bool oneRow = 0;
        for (int v = 0; !oneRow && v < graph.size(); v++)
            if (graph[v].size() == 1)
                oneRow = 1;
        
        vector<int> visited(graph.size());
        vector<vector<int>> res;

        for (int y = 0; res.empty() || y * res.back().size() < graph.size(); y++) {
            res.push_back({ getBestTo(graph, visited, y ? res[y - 1][0] : -1) });

            for (int x = 1; 1; x++) {
                int to = getBestTo(graph, visited, y ? res[y - 1][x] : res[0][x - 1]);
                res.back().push_back(to);
                if (!y && getDegree(graph, visited, to) <= (oneRow ? 0 : 1) || y && x + 1 == res[y - 1].size())
                    break;
            }
        }
        
        return res;
    }
};