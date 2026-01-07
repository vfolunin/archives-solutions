class Solution {
    void dfs(vector<vector<int>> &graph, int v, vector<int> &visited, bool &hasCycle) {
        visited[v] = 1;
        for (int to : graph[v]) {
            if (visited[to] == 0) {
                dfs(graph, to, visited, hasCycle);
                if (hasCycle)
                    return;
            } else if (visited[to] == 1) {
                hasCycle = 1;
                return;
            }
        }
        visited[v] = 2;
    }

    bool isAcyclic(vector<vector<int>> &graph) {
        vector<int> visited(graph.size());
        bool hasCycle = 0;
        for (int v = 0; v < graph.size() && !hasCycle; v++)
            if (!visited[v])
                dfs(graph, v, visited, hasCycle);
        return !hasCycle;
    }

public:
    vector<vector<int>> supersequences(vector<string> &words) {
        vector<int> letterMap(26, -1);
        int letterCount = 0;
        for (string &word : words)
            for (char letter : word)
                if (letterMap[letter - 'a'] == -1)
                    letterMap[letter - 'a'] = letterCount++;

        for (int doubleCount = 0; 1; doubleCount++) {
            string mask = string(letterCount - doubleCount, 0) + string(doubleCount, 1);
            vector<vector<int>> res;

            do {
                vector<vector<int>> graph(letterCount);
                for (string &word : words) {
                    int a = letterMap[word[0] - 'a'];
                    int b = letterMap[word[1] - 'a'];
                    if (!mask[a] && !mask[b])
                        graph[a].push_back(b);
                }

                if (isAcyclic(graph)) {
                    vector<int> row(26);
                    for (string &word : words)
                        row[word[0] - 'a'] = row[word[1] - 'a'] = 1;
                    for (int i = 0; i < row.size(); i++)
                        if (letterMap[i] != -1)
                            row[i] += mask[letterMap[i]];
                    res.push_back(row);
                }
            } while (next_permutation(mask.begin(), mask.end()));

            if (!res.empty())
                return res;
        }
    }
};