class Solution {
    void dfs(vector<vector<int>> &graph, int v, vector<int> &visited, int color) {
        visited[v] = color;
        for (int to : graph[v])
            if (!visited[to])
                dfs(graph, to, visited, color);
    }
    
public:
    string smallestStringWithSwaps(string s, vector<vector<int>> &pairs) {
        vector<vector<int>> graph(s.size());
        for (vector<int> &pair : pairs) {
            graph[pair[0]].push_back(pair[1]);
            graph[pair[1]].push_back(pair[0]);
        }
        
        vector<int> visited(s.size());
        vector<string> groups;
        for (int i = 0; i < s.size(); i++) {
            if (!visited[i]) {
                groups.emplace_back();
                dfs(graph, i, visited, groups.size());
            }
            groups[visited[i] - 1] += s[i];
        }
        
        for (string &group : groups)
            sort(group.begin(), group.end());
        
        vector<int> index(groups.size());
        string res;
        for (int i = 0; i < s.size(); i++)
            res += groups[visited[i] - 1][index[visited[i] - 1]++];
        return res;
    }
};