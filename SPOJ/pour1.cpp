#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <string>
using namespace std;

int bfs(int a, int b, int c) {
    map<pair<int, int>, int> dist;
    queue<int> q;

    dist[{ 0, 0 }] = 0;
    q.push(0);
    q.push(0);

    while (!q.empty()) {
        int curA = q.front();
        q.pop();
        int curB = q.front();
        q.pop();

        int curDist = dist[{ curA, curB }];
        if (curA == c || curB == c)
            return curDist;

        if (!dist.count({ 0, curB })) {
            dist[{ 0, curB }] = curDist + 1;
            q.push(0);
            q.push(curB);
        }
        if (!dist.count({ curA, 0 })) {
            dist[{ curA, 0 }] = curDist + 1;
            q.push(curA);
            q.push(0);
        }
        if (!dist.count({ a, curB })) {
            dist[{ a, curB }] = curDist + 1;
            q.push(a);
            q.push(curB);
        }
        if (!dist.count({ curA, b })) {
            dist[{ curA, b }] = curDist + 1;
            q.push(curA);
            q.push(b);
        }
        int ab = min(curA, b - curB);
        if (!dist.count({ curA - ab, curB + ab })) {
            dist[{ curA - ab, curB + ab }] = curDist + 1;
            q.push(curA - ab);
            q.push(curB + ab);
        }
        int ba = min(a - curA, curB);
        if (!dist.count({ curA + ba, curB - ba })) {
            dist[{ curA + ba, curB - ba }] = curDist + 1;
            q.push(curA + ba);
            q.push(curB - ba);
        }
    }

    return -1;
}

void solve() {
    int a, b, c;
    cin >> a >> b >> c;

    cout << bfs(a, b, c) << "\n";
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int n;
    cin >> n;

    for (int i = 0; i < n; i++)
        solve();
}