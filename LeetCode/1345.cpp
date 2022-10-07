class Solution {
    int bfs(vector<int> &a, unordered_map<int, vector<int>> &pos) {
        vector<int> dist(a.size(), 1e9);
        queue<int> q;
        
        dist[0] = 0;
        q.push(0);
        
        while (!q.empty()) {
            int v = q.front();
            q.pop();
            
            if (v == a.size() - 1)
                return dist[v];
            
            for (int to : pos[a[v]]) {
                if (dist[to] > dist[v] + 1) {
                    dist[to] = dist[v] + 1;
                    q.push(to);
                }
            }
            
            pos[a[v]].clear();
            
            for (int to : { v - 1, v + 1 }) {
                if (0 <= to && to < a.size() && dist[to] > dist[v] + 1) {
                    dist[to] = dist[v] + 1;
                    q.push(to);
                }
            }
        }
        
        return -1;
    }
    
public:
    int minJumps(vector<int> &a) {
        unordered_map<int, vector<int>> pos;
        for (int i = 0; i < a.size(); i++)
            pos[a[i]].push_back(i);
        
        return bfs(a, pos);
    }
};