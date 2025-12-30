class Solution {
    int bfs(int divisor) {
        vector<int> dist(divisor, 1e9);
        queue<int> q;

        dist[1 % divisor] = 1;
        q.push(1 % divisor);

        while (!q.empty()) {
            int v = q.front();
            q.pop();
            
            if (!v)
                return dist[v];

            int to = (v * 10 + 1) % divisor;
            if (dist[to] > dist[v] + 1) {
                dist[to] = dist[v] + 1;
                q.push(to);
            }
        }

        return -1;
    }
    
public:
    int minAllOneMultiple(int divisor) {
        return bfs(divisor);
    }
};