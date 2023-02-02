class Solution {
    void dfs(unordered_map<char, unordered_set<char>> &graph, char v,
             unordered_map<char, int> &visited, string &order, bool &hasCycle) {
        visited[v] = 1;

        for (char to : graph[v]) {
            if (visited[to] == 0)
                dfs(graph, to, visited, order, hasCycle);
            else if (visited[to] == 1)
                hasCycle = 1;
        }

        order += v;

        visited[v] = 2;
    }

public:
    string alienOrder(vector<string> &words) {
        unordered_map<char, unordered_set<char>> graph;

        for (string &word : words)
            for (char c : word)
                graph[c];

        for (int i = 0; i + 1 < words.size(); i++) {
            int j = 0;
            while (j < words[i].size() && j < words[i + 1].size() && words[i][j] == words[i + 1][j])
                j++;
            
            if (j < words[i].size() && j < words[i + 1].size())
                graph[words[i][j]].insert(words[i + 1][j]);
            else if (words[i].size() > words[i + 1].size())
                return "";
        }

        unordered_map<char, int> visited;
        string order;
        bool hasCycle = 0;

        for (auto &[v, adjacent] : graph)
            if (!visited[v])
                dfs(graph, v, visited, order, hasCycle);
        
        if (hasCycle)
            return "";
        
        reverse(order.begin(), order.end());
        return order;
    }
};