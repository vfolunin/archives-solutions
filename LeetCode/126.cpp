class Solution {
    int hamming(string &a, string &b) {
        int diff = 0;
        for (int i = 0; i < a.size(); i++)
            diff += a[i] != b[i];
        return diff;
    }
    
    vector<int> bfs(vector<vector<int>> &graph, int start) {
        vector<int> dist(graph.size(), 1e9);
        queue<int> q;

        dist[start] = 0;
        q.push(start);

        while (!q.empty()) {
            int v = q.front();
            q.pop();

            for (int to : graph[v]) {
                if (dist[to] > dist[v] + 1) {
                    dist[to] = dist[v] + 1;
                    q.push(to);
                }
            }
        }

        return dist;
    }
    
    void rec(vector<vector<int>> &graph, int v, vector<int> &dist, vector<string> &words,
             vector<string> &path, vector<vector<string>> &paths) {
        path.push_back(words[v]);
        
        if (!dist[v]) {
            paths.push_back(path);
        } else {
            for (int to : graph[v])
                if (dist[to] < dist[v])
                    rec(graph, to, dist, words, path, paths);
        }
        
        path.pop_back();
    }
    
public:
    vector<vector<string>> findLadders(string &start, string &finish, vector<string> &words) {
        words.push_back(start);
        
        vector<vector<int>> graph(words.size());
        for (int a = 0; a < words.size(); a++)
            for (int b = 0; b < words.size(); b++)
                if (hamming(words[a], words[b]) == 1)
                    graph[a].push_back(b);
        
        int startV = words.size() - 1, finishV = find(words.begin(), words.end(), finish) - words.begin();
        if (finishV == words.size())
            return {};
        
        vector<int> dist = bfs(graph, finishV);
        if (dist[startV] == 1e9)
            return {};
        
        vector<string> path;
        vector<vector<string>> paths;
        rec(graph, startV, dist, words, path, paths);
        return paths;
    }
};