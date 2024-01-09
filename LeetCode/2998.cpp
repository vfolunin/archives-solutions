class Solution {
    int bfs(int start, int finish) {
        vector<int> dist(2e4, 1e9);
        queue<int> q;
        
        dist[start] = 0;
        q.push(start);
        
        while (!q.empty()) {
            int v = q.front();
            q.pop();

            if (v == finish)
                return dist[v];
            
            vector<int> to;
            for (int delta : { -1, 1 })
                if (0 <= v + delta && v + delta < dist.size())
                    to.push_back(v + delta);
            for (int divisor : { 5, 11 })
                if (v % divisor == 0)
                    to.push_back(v / divisor);

            for (int to : to) {
                if (dist[to] > dist[v] + 1) {
                    dist[to] = dist[v] + 1;
                    q.push(to);
                }
            }
        }

        return -1;
    }

public:
    int minimumOperationsToMakeEqual(int start, int finish) {
        return bfs(start, finish);
    }
};