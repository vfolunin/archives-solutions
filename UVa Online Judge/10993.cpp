#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <string>
using namespace std;

string bfs(string &digits, int mod) {
    vector<int> dist(mod, 1e9);
    vector<int> prev(mod, -1);
    vector<char> digit(mod);
    queue<int> q;

    for (char d : digits) {
        if (d != '0') {
            int v = (d - '0') % mod;
            if (dist[v] == 1e9) {
                dist[v] = 1;
                digit[v] = d;
                q.push(v);
            }
        }
    }

    while (!q.empty()) {
        int v = q.front();
        q.pop();

        for (char d : digits) {
            int to = (v * 10 + d - '0') % mod;
            if (dist[to] == 1e9) {
                dist[to] = dist[v] + 1;
                prev[to] = v;
                digit[to] = d;
                q.push(to);
            }
        }
    }

    if (dist[0] == 1e9)
        return "impossible";

    string res;
    for (int v = 0; v != -1; v = prev[v])
        res += digit[v];
    reverse(res.begin(), res.end());
    return res;
}

bool solve() {
    string digits;
    int mod;
    cin >> digits >> mod;

    if (!mod)
        return 0;

    sort(digits.begin(), digits.end());
    cout << bfs(digits, mod) << "\n";
    return 1;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    while (solve());
}