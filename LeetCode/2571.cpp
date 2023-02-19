class Solution {
    vector<int> bfs() {
        vector<int> dist(2e5, 1e9);
        queue<int> q;

        dist[0] = 0;
        q.push(0);

        while (!q.empty()) {
            int v = q.front();
            q.pop();

            for (int delta = 1; delta < dist.size(); delta *= 2) {
                for (int to : { v - delta, v + delta }) {
                    if (0 <= to && to < dist.size() && dist[to] > dist[v] + 1) {
                        dist[to] = dist[v] + 1;
                        q.push(to);
                    }
                }
            }
        }

        return dist;
    }
    
public:
    int minOperations(int n) {
        static vector<int> dist = bfs();
        return dist[n];
    }
};