class Solution {
    void dfs(unordered_map<int, vector<int>> &graph, int v, vector<int> &res) {
        res.push_back(v);
        for (int to : graph[v])
            dfs(graph, to, res);
    }

public:
    vector<int> killProcess(vector<int> &pid, vector<int> &ppid, int kill) {
        unordered_map<int, vector<int>> graph;
        for (int i = 0; i < pid.size(); i++)
            graph[ppid[i]].push_back(pid[i]);
        
        vector<int> res;
        dfs(graph, kill, res);
        return res;
    }
};