#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <string>
using namespace std;

bool isPrime(int n) {
    for (int d = 2; d * d <= n; d++)
        if (n % d == 0)
            return 0;
    return 1;
}

vector<int> makeTo(vector<int> &v, int pos1, int pos2) {
    vector<int> to = v;
    to.erase(to.begin() + pos1);
    to.insert(to.begin() + pos2, v[pos1]);
    return to;
}

int bfs(vector<int> &p) {
    map<vector<int>, int> dist;
    queue<vector<int>> q;

    dist[p] = 0;
    q.push(p);

    while (!q.empty()) {
        vector<int> v = q.front();
        q.pop();
        int d = dist[v];

        bool final = 1;
        for (int i = 0; final && i < v.size(); i++)
            final &= abs(v[i]) == i + 1;

        if (final)
            return d;

        for (int i = 0; i < v.size(); i++) {
            for (int j = i + 1; j < v.size(); j++) {
                if (v[i] > 0 && v[j] > 0 || v[i] < 0 && v[j] < 0 || !isPrime(abs(v[i]) + abs(v[j])))
                    continue;

                vector<int> to;
                
                to = makeTo(v, j, i);
                if (!dist.count(to)) {
                    dist[to] = dist[v] + 1;
                    q.push(to);
                }

                to = makeTo(v, j, i + 1);
                if (!dist.count(to)) {
                    dist[to] = dist[v] + 1;
                    q.push(to);
                }

                to = makeTo(v, i, j - 1);
                if (!dist.count(to)) {
                    dist[to] = dist[v] + 1;
                    q.push(to);
                }

                to = makeTo(v, i, j);
                if (!dist.count(to)) {
                    dist[to] = dist[v] + 1;
                    q.push(to);
                }
            }
        }
    }

    return -1;
}

bool solve(int test) {
    vector<int> p(8);
    for (int &x : p)
        if (!(cin >> x))
            return 0;

    cout << "Case " << test << ": " << bfs(p) << "\n";
    return 1;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    for (int test = 1; solve(test); test++);
}