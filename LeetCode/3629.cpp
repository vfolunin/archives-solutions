class Solution {
    vector<int> getPrimeDivisors(int n) {
        vector<int> primeDivisors;
        
        for (long long d = 2; d * d <= n; d++) {
            if (n % d == 0) {
                primeDivisors.push_back(d);
                while (n % d == 0)
                    n /= d;
            }
        }
        if (n != 1)
            primeDivisors.push_back(n);

        return primeDivisors;
    }

    int bfs(vector<int> &a, unordered_map<int, vector<int>> &jumps) {
        vector<int> dist(a.size(), 1e9);
        queue<int> q;

        dist[0] = 0;
        q.push(0);

        while (!q.empty()) {
            int v = q.front();
            q.pop();

            for (int to : { v - 1, v + 1 }) {
                if (0 <= to && to < a.size() && dist[to] > dist[v] + 1) {
                    dist[to] = dist[v] + 1;
                    q.push(to);
                }
            }

            if (jumps.count(a[v])) {
                for (int to : jumps[a[v]]) {
                    if (dist[to] > dist[v] + 1) {
                        dist[to] = dist[v] + 1;
                        q.push(to);
                    }
                }
                jumps.erase(a[v]);
            }
        }

        return dist.back();
    }

public:
    int minJumps(vector<int> &a) {
        unordered_map<int, vector<int>> jumps;
        for (int i = 0; i < a.size(); i++)
            for (int p : getPrimeDivisors(a[i]))
                jumps[p].push_back(i);
        
        return bfs(a, jumps);
    }
};