class Solution {
    void rec(vector<vector<int>> &graph, int v, vector<int> &path, vector<vector<int>> &paths) {
        path.push_back(v);
        if (v == graph.size() - 1) {
            paths.push_back(path);
        } else {
            for (int to : graph[v])
                rec(graph, to, path, paths);
        }
        path.pop_back();
    }
    
public:
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>> &graph) {
        vector<int> path;
        vector<vector<int>> paths;
        rec(graph, 0, path, paths);
        return paths;
    }
};