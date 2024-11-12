#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <string>
using namespace std;

void printPath(vector<pair<int, int>> &from, int finish) {
    vector<int> path;
    for (int v = finish; v != -1; v = from[v].first)
        path.push_back(from[v].second);
    reverse(path.begin(), path.end());
    for (int v : path)
        cout << v;
}

void bfs(string &digits, int divisor) {
    vector<int> dist(divisor, 1e9);
    vector<pair<int, int>> from(divisor, { -1, -1 });
    queue<int> q;

    for (char c : digits) {
        if (c == '0')
            continue;
        int v = (c - '0') % divisor;
        if (dist[v] > 0) {
            dist[v] = 0;
            from[v] = { -1, c - '0' };
            q.push(v);
        }
    }

    while (!q.empty()) {
        int v = q.front();
        q.pop();

        if (v == 0) {
            printPath(from, v);
            return;
        }

        for (char c : digits) {
            int to = (v * 10 + c - '0') % divisor;
            if (dist[to] > dist[v] + 1) {
                dist[to] = dist[v] + 1;
                from[to] = { v, c - '0' };
                q.push(to);
            }
        }
    }

    cout << 0;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int divisor;
    string digits;
    cin >> divisor >> digits;

    sort(digits.begin(), digits.end());

    bfs(digits, divisor);
}