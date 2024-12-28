#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <string>
using namespace std;

vector<int> bfs(int start) {
    vector<int> dist(1000, 1e9);
    queue<int> q;

    dist[start] = 0;
    q.push(start);

    while (!q.empty()) {
        int v = q.front();
        q.pop();

        for (int to : { v - 1, v + 1, v * 3 }) {
            if (0 < to && to < dist.size() && dist[to] > dist[v] + 1) {
                dist[to] = dist[v] + 1;
                q.push(to);
            }
        }
    }

    return dist;
}

int greedy(long long n) {
    if (n < 100) {
        static vector<int> dist = bfs(1);
        return dist[n];
    }
    if (n % 3 == 0)
        return 1 + greedy(n / 3);
    else if (n % 3 == 1)
        return 1 + greedy(n - 1);
    else
        return 1 + greedy(n + 1);
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    long long n;
    cin >> n;

    cout << greedy(n);
}