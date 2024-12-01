class Solution {
    void dfs(vector<vector<int>> &graph, int v, int p, int depth, vector<int> &level) {
        level[v] = depth % 2;

        for (int to : graph[v])
            if (to != p) 
                dfs(graph, to, v, depth + 1, level);
    }

public:
    vector<int> maxTargetNodes(vector<vector<int>> &edges1, vector<vector<int>> &edges2) {
        vector<vector<int>> graph1(edges1.size() + 1);
        for (vector<int> &edge : edges1) {
            graph1[edge[0]].push_back(edge[1]);
            graph1[edge[1]].push_back(edge[0]);
        }

        vector<int> level1(graph1.size());
        dfs(graph1, 0, -1, 0, level1);
        vector<int> count1(2);
        for (int level : level1)
            count1[level]++;
        
        vector<vector<int>> graph2(edges2.size() + 1);
        for (vector<int> &edge : edges2) {
            graph2[edge[0]].push_back(edge[1]);
            graph2[edge[1]].push_back(edge[0]);
        }

        vector<int> level2(graph2.size());
        dfs(graph2, 0, -1, 0, level2);
        vector<int> count2(2);
        for (int level : level2)
            count2[level]++;
        int maxCount2 = max(count2[0], count2[1]);

        vector<int> res(graph1.size());
        for (int v = 0; v < graph1.size(); v++)
            res[v] = count1[level1[v]] + maxCount2;
        return res;
    }
};