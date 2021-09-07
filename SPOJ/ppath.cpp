#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <string>
using namespace std;

vector<int> getFourDigitPrimes() {
    const int N = 1e5;
    vector<int> isPrime(N, 1), primes;
    for (int i = 2; i < N; i++) {
        if (isPrime[i]) {
            if (1000 <= i)
                primes.push_back(i);
            for (long long j = 1LL * i * i; j < N; j += i)
                isPrime[j] = 0;
        }
    }
    return primes;
}

int bfs(vector<vector<int>> &graph, int start, int finish) {
    vector<int> dist(graph.size(), -1);
    queue<int> q;

    dist[start] = 0;
    q.push(start);

    while (!q.empty()) {
        int v = q.front();
        q.pop();

        for (int to : graph[v]) {
            if (dist[to] == -1) {
                dist[to] = dist[v] + 1;
                q.push(to);
            }
        }
    }

    return dist[finish];
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    vector<int> primes = getFourDigitPrimes();
    vector<vector<int>> graph(primes.size());

    for (int v = 0; v < primes.size(); v++) {
        string s = to_string(primes[v]);
        for (int i = 0; i < s.size(); i++) {
            char c = s[i];
            for (s[i] = '0'; s[i] <= '9'; s[i]++) {
                int n = stoi(s);
                int to = lower_bound(primes.begin(), primes.end(), n) - primes.begin();
                if (to != primes.size() && n == primes[to] && v != to)
                    graph[v].push_back(to);
            }
            s[i] = c;
        }
    }
    
    int queryCount;
    cin >> queryCount;

    for (int i = 0; i < queryCount; i++) {
        int na, nb;
        cin >> na >> nb;
        int a = lower_bound(primes.begin(), primes.end(), na) - primes.begin();
        int b = lower_bound(primes.begin(), primes.end(), nb) - primes.begin();
        cout << bfs(graph, a, b) << "\n";
    }
}