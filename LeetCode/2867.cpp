class Solution {
    vector<int> getPrimes(int n) {
        vector<int> isPrime(n + 1, 1), primes;

        for (int i = 2; i < isPrime.size(); i++) {
            if (isPrime[i]) {
                primes.push_back(i);
                for (long long j = 1LL * i * i; j < isPrime.size(); j += i)
                    isPrime[j] = 0;
            }
        }

        return primes;
    }

    bool isPrime(int n) {
        static vector<int> primes = getPrimes(1e5);
        return binary_search(primes.begin(), primes.end(), n);
    }

    pair<int, int> dfs(vector<vector<int>> &graph, int v, int p, long long &res) {
        int ways1 = isPrime(v + 1), ways0 = !ways1;

        for (int to : graph[v]) {
            if (to == p)
                continue;

            auto [to0, to1] = dfs(graph, to, v, res);
            res += ways0 * to1 + ways1 * to0;

            if (isPrime(v + 1)) {
                ways1 += to0;
            } else {
                ways0 += to0;
                ways1 += to1;
            }
        }
        
        return { ways0, ways1 };
    }

public:
    long long countPaths(int vertexCount, vector<vector<int>> &edges) {
        vector<vector<int>> graph(vertexCount);
        for (vector<int> &edge : edges) {
            graph[edge[0] - 1].push_back(edge[1] - 1);
            graph[edge[1] - 1].push_back(edge[0] - 1);
        }

        long long res = 0;
        dfs(graph, 0, -1, res);
        return res;
    }
};