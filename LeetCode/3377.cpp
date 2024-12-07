class Solution {
    bool isPrime(int n) {
        if (n < 2)
            return 0;

        for (long long d = 2; d * d <= n; d++)
            if (n % d == 0)
                return 0;

        return 1;
    }

    vector<int> getNeighbors(int v) {
        vector<int> neighbors;
        string s = to_string(v);
        for (int i = 0; i < s.size(); i++) {
            if (s[i] != '0') {
                s[i]--;
                if (int to = stoi(s); s[0] != '0' && !isPrime(to))
                    neighbors.push_back(to);
                s[i]++;
            }
            if (s[i] != '9') {
                s[i]++;
                if (int to = stoi(s); !isPrime(to))
                    neighbors.push_back(to);
                s[i]--;
            }
        }
        return neighbors;
    }

    int dijkstra(int start, int finish) {
        vector<int> dist(1e4, 1e9);
        set<pair<int, int>> q;

        if (!isPrime(start)) {
            dist[start] = start;
            q.insert({ dist[start], start });
        }

        while (!q.empty()) {
            int v = q.begin()->second;
            q.erase(q.begin());

            if (v == finish)
                return dist[v];

            for (int to : getNeighbors(v)) {
                if (dist[to] > dist[v] + to) {
                    q.erase({ dist[to], to });
                    dist[to] = dist[v] + to;
                    q.insert({ dist[to], to });
                }
            }
        }

        return -1;
    }

public:
    int minOperations(int start, int finish) {
        return dijkstra(start, finish);
    }
};