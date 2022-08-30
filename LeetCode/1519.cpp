class Solution {
    unordered_map<char, int> rec(vector<vector<int>> &graph, string &s, int v, int p, vector<int> &res) {
        unordered_map<char, int> count = { { s[v], 1 } };
        
        for (int to : graph[v]) {
            if (to == p)
                continue;
            
            unordered_map<char, int> childCount = rec(graph, s, to, v, res);
            if (count.size() < childCount.size())
                swap(count, childCount);
            for (auto &[c, delta] : childCount)
                count[c] += delta;
        }
        
        res[v] = count[s[v]];
        
        return count;
    }
    
public:
    vector<int> countSubTrees(int vertexCount, vector<vector<int>> &edges, string &s) {
        vector<vector<int>> graph(vertexCount);
        for (vector<int> &edge : edges) {
            graph[edge[0]].push_back(edge[1]);
            graph[edge[1]].push_back(edge[0]);
        }
        
        vector<int> res(vertexCount);
        rec(graph, s, 0, -1, res);
        return res;
    }
};