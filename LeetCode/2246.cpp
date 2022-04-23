class Solution {
    int dfs(vector<vector<int>> &graph, int v, string &s, int &maxPathSize) {
        vector<int> childSizes = { 0, 0 };
        for (int to : graph[v]) {
            int childSize = dfs(graph, to, s, maxPathSize);
            if (s[v] != s[to])
                childSizes.push_back(childSize);
        }
        sort(childSizes.rbegin(), childSizes.rend());
        maxPathSize = max(maxPathSize, childSizes[0] + childSizes[1] + 1);
        return childSizes[0] + 1;
    }
    
public:
    int longestPath(vector<int> &parent, string s) {
        vector<vector<int>> graph(parent.size());
        for (int v = 1; v < parent.size(); v++)
            graph[parent[v]].push_back(v);
        
        int res = 0;
        dfs(graph, 0, s, res);
        return res;
    }
};