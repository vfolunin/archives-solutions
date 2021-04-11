#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <string>
using namespace std;

void solve(int test) {
    int len, switchCount;
    cin >> len >> switchCount;

    vector<int> switches(switchCount);
    for (int &s : switches) {
        int bulbCount;
        cin >> bulbCount;

        for (int i = 0; i < bulbCount; i++) {
            int bulb;
            cin >> bulb;
            s |= 1 << bulb;
        }
    }

    vector<int> dist(1 << len, -1);
    queue<int> q;

    dist[0] = 0;
    q.push(0);

    while (!q.empty()) {
        int v = q.front();
        q.pop();

        for (int s : switches) {
            int to = v ^ s;
            if (dist[to] == -1) {
                dist[to] = dist[v] + 1;
                q.push(to);
            }
        }
    }

    int queryCount;
    cin >> queryCount;

    cout << "Case " << test << ":\n";
    for (int i = 0; i < queryCount; i++) {
        string s;
        cin >> s;

        int v = 0;
        for (char c : s)
            v = v * 2 + c - '0';

        cout << dist[v] << "\n";
    }
    cout << "\n";
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int n;
    cin >> n;

    for (int test = 1; test <= n; test++)
        solve(test);
}