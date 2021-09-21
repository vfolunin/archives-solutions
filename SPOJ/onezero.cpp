#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <string>
using namespace std;

string bfs(int mod) {
    vector<int> prev(mod, -1);
    vector<char> prevC(mod, -1);
    queue<int> q;

    prev[1 % mod] = -2;
    prevC[1 % mod] = '1';
    q.push(1 % mod);

    while (!q.empty()) {
        int v = q.front();
        q.pop();

        for (int digit = 0; digit < 2; digit++) {
            int to = (10 * v + digit) % mod;
            if (prev[to] == -1) {
                prev[to] = v;
                prevC[to] = digit + '0';
                q.push(to);
            }
        }
    }

    string res;
    for (int v = 0; v != -2; v = prev[v])
        res += prevC[v];
    reverse(res.begin(), res.end());
    return res;
}

void solve() {
    int mod;
    cin >> mod;

    cout << bfs(mod) << "\n";
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int n;
    cin >> n;

    for (int i = 0; i < n; i++)
        solve();
}