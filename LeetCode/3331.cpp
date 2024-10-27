class Solution {
    void dfs1(vector<vector<int>> &graph1, int v, int p, string &s, vector<vector<int>> &from2, vector<vector<int>> &graph2) {
        if (p != -1)
            graph2[from2[s[v] - 'a'].empty() ? p : from2[s[v] - 'a'].back()].push_back(v);
        
        from2[s[v] - 'a'].push_back(v);

        for (int to : graph1[v])
            dfs1(graph1, to, v, s, from2, graph2);
        
        from2[s[v] - 'a'].pop_back();
    }

    int dfs2(vector<vector<int>> &graph2, int v, vector<int> &res) {
        res[v] = 1;

        for (int to : graph2[v])
            res[v] += dfs2(graph2, to, res);
        
        return res[v];
    }

public:
    vector<int> findSubtreeSizes(vector<int> &from, string &s) {
        vector<vector<int>> graph1(from.size());
        for (int v = 1; v < graph1.size(); v++)
            graph1[from[v]].push_back(v);
        
        vector<vector<int>> graph2(from.size());
        vector<vector<int>> from2(26);
        dfs1(graph1, 0, -1, s, from2, graph2);

        vector<int> res(from.size());
        dfs2(graph2, 0, res);
        return res;
    }
};