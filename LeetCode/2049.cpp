class Solution {
    int dfs(vector<vector<int>> &graph, int v, map<long long, int> &res) {
        int size = 1;
        long long product = 1;
        
        for (int to : graph[v]) {
            int childSize = dfs(graph, to, res);
            size += childSize;
            product *= childSize;
        }
        
        if (size != graph.size())
            product *= graph.size() - size;
        res[product]++;
        
        return size;
    }
    
public:
    int countHighestScoreNodes(vector<int> &p) {
        vector<vector<int>> graph(p.size());
        for (int v = 1; v < p.size(); v++)
            graph[p[v]].push_back(v);
        
        map<long long, int> res;
        dfs(graph, 0, res);
        
        return prev(res.end())->second;
    }
};