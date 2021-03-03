#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <string>
using namespace std;

bool isPrime(int n) {
    if (n < 2)
        return 0;
    for (int i = 2; i * i <= n; i++)
        if (n % i == 0)
            return 0;
    return 1;
}

void solve() {
    string a, b;
    cin >> a >> b;

    map<string, int> dist;
    queue<string> q;

    dist[a] = 0;
    q.push(a);

    while (!q.empty()) {
        string v = q.front();
        q.pop();

        string to = v;
        for (int i = 0; i < 4; i++) {
            for (to[i] = i ? '0' : '1'; to[i] <= '9'; to[i]++) {
                if (!dist.count(to) && isPrime(stoi(to))) {
                    dist[to] = dist[v] + 1;
                    q.push(to);
                }
            }
            to[i] = v[i];
        }
    }

    if (!dist.count(b))
        cout << "impossible\n";
    else
        cout << dist[b] << "\n";
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int n;
    cin >> n;

    for (int i = 0; i < n; i++)
        solve();
}