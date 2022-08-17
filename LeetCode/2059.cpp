class Solution {
    int bfs(vector<int> &a, int start, int finish) {
        vector<int> dist(1001, 1e9);
        queue<int> q;

        dist[start] = 0;
        q.push(start);

        while (!q.empty()) {
            int v = q.front();
            q.pop();
            
            if (v == finish)
                return dist[v];

            for (int value : a) {
                for (int to : { v - value, v + value, v ^ value }) {
                    if (to == finish) {
                        return dist[v] + 1;
                    } else if (0 <= to && to < dist.size() && dist[to] > dist[v] + 1) {
                        dist[to] = dist[v] + 1;
                        q.push(to);
                    }
                }
            }
        }

        return -1;
    }
    
public:
    int minimumOperations(vector<int> &a, int start, int finish) {
        return bfs(a, start, finish);
    }
};