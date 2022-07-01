class Solution {
    int hamming(string &a, string &b) {
        int res = 0;
        for (int i = 0; i < a.size(); i++)
            res += a[i] != b[i];
        return res;
    }
    
    int bfs(unordered_map<string, unordered_set<string>> &graph, string &start, string &finish) {
        unordered_map<string, int> dist;
        queue<string> q;
        
        dist[start] = 0;
        q.push(start);
        
        while (!q.empty()) {
            string v = q.front();
            q.pop();
            
            if (v == finish)
                return dist[v];
            
            for (const string &to : graph[v]) {
                if (!dist.count(to)) {
                    dist[to] = dist[v] + 1;
                    q.push(to);
                }
            }
        }
        
        return -1;
    }
    
public:
    int minMutation(string &start, string &finish, vector<string> &bank) {
        bank.push_back(start);
        
        unordered_map<string, unordered_set<string>> graph;
        for (string &a : bank)
            for (string &b : bank)
                if (hamming(a, b) == 1)
                    graph[a].insert(b);
        
        return bfs(graph, start, finish);
    }
};