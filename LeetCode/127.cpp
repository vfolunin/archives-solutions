class Solution {
    bool singleDiff(string &a, string &b) {
        int diff = 0;
        for (int i = 0; diff <= 1 && i < a.size(); i++)
            diff += a[i] != b[i];
        return diff == 1;
    }
    
    int bfs(vector<vector<int>> &graph, int start, int finish) {
        vector<int> dist(graph.size(), 1e9);
        queue<int> q;
        
        dist[start] = 1;
        q.push(start);
        
        while (!q.empty()) {
            int v = q.front();
            q.pop();
            
            if (v == finish)
                return dist[v];
            
            for (int to : graph[v]) {
                if (dist[to] > dist[v] + 1) {
                    dist[to] = dist[v] + 1;
                    q.push(to);
                }
            }
        }
        
        return 0;
    }
    
public:
    int ladderLength(string &a, string &b, vector<string> &words) {
        int finish = find(words.begin(), words.end(), b) - words.begin();
        if (finish == words.size())
            return 0;
        
        words.push_back(a);
        int start = words.size() - 1;
        
        vector<vector<int>> graph(words.size());
        for (int a = 0; a < words.size(); a++) {
            for (int b = a + 1; b < words.size(); b++) {
                if (singleDiff(words[a], words[b])) {
                    graph[a].push_back(b);
                    graph[b].push_back(a);
                }
            }
        }
        
        return bfs(graph, start, finish);
    }
};