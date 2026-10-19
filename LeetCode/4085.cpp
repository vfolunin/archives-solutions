class Solution {
    bool dfs(vector<vector<int>> &graph, int v, vector<int> &visited) {
        visited[v] = 1;
        bool ok = graph[v].size() <= 2;
        for (int to : graph[v])
            ok &= dfs(graph, to, visited);
        return ok;
    }

public:
    int findColoredRoot(vector<vector<int>> &edges, string &color) {
        vector<vector<int>> graph(color.size());
        vector<bool> canBeRoot(graph.size(), 1);

        for (vector<int> &edge : edges) {
            int a = edge[0], b = edge[1];
            
            static string colors = "RBW";
            int ai = colors.find(color[a]), bi = colors.find(color[b]);

            if ((ai + 1) % colors.size() == bi) {
                graph[a].push_back(b);
                canBeRoot[b] = 0;
            } else if ((bi + 1) % colors.size() == ai) {
                graph[b].push_back(a);
                canBeRoot[a] = 0;
            } else {
                return -1;
            }
        }

        int root = find(canBeRoot.begin(), canBeRoot.end(), 1) - canBeRoot.begin();
        vector<int> visited(graph.size());
        if (root < graph.size() && dfs(graph, root, visited) && !count(visited.begin(), visited.end(), 0))
            return root;
        else
            return -1;
    }
};