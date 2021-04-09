#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <string>
using namespace std;

bool solve() {
    int mod;
    cin >> mod;

    if (!mod)
        return 0;

    if (mod == 1) {
        cout << "1\n";
        return 1;
    }

    vector<string> multiple(mod);
    multiple[1] = "1";

    queue<int> q;
    q.push(1);

    while (!q.empty()) {
        int v = q.front();
        q.pop();

        if (multiple[v * 10 % mod].empty()) {
            multiple[v * 10 % mod] = multiple[v] + '0';
            q.push(v * 10 % mod);
        }

        if (multiple[(v * 10 + 1) % mod].empty()) {
            multiple[(v * 10 + 1) % mod] = multiple[v] + '1';
            q.push((v * 10 + 1) % mod);
        }
    }

    cout << multiple[0] << "\n";
    return 1;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    while (solve());
}