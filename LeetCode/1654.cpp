class Solution {
    int bfs(vector<int> &forbidden, int forward, int backward, int target) {
        vector<vector<int>> dist(1e4, vector<int>(2, 1e9));
        queue<pair<int, int>> q;
        
        dist[0][0] = 0;
        q.push({ 0, 0 });
        
        while (!q.empty()) {
            auto [v, last] = q.front();
            q.pop();
            
            if (v == target)
                return dist[v][last];
            
            if (v + forward < dist.size() && dist[v + forward][0] == 1e9 &&
                !binary_search(forbidden.begin(), forbidden.end(), v + forward)) {
                dist[v + forward][0] = dist[v][last] + 1;
                q.push({ v + forward, 0 });
            }
            if (v - backward >= 0 && !last && dist[v - backward][1] == 1e9 &&
                !binary_search(forbidden.begin(), forbidden.end(), v - backward)) {
                dist[v - backward][1] = dist[v][last] + 1;
                q.push({ v - backward, 1 });
            }
        }
        
        return -1;
    }
    
public:
    int minimumJumps(vector<int> &forbidden, int forward, int backward, int target) {
        sort(forbidden.begin(), forbidden.end());
        return bfs(forbidden, forward, backward, target);
    }
};