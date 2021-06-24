#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

bool solve() {
    int n;
    if (!(cin >> n))
        return 0;

    vector<vector<int>> a(n, vector<int>(n));
    for (vector<int> &row : a) {
        for (int &x : row)
            cin >> x;
        sort(row.begin(), row.end());
    }

    int sum = 0;
    vector<int> pos(n);
    for (int i = 0; i < n; i++)
        sum += a[i][0];

    set<pair<int, vector<int>>> q = { { sum, pos } };

    for (int i = 0; i < n; i++) {
        auto [sum, pos] = *q.begin();
        q.erase(q.begin());

        cout << sum << (i + 1 < n ? " " : "\n");

        if (i + 1 == n)
            break;

        for (int i = 0; i < n; i++) {
            if (pos[i] + 1 < n) {
                sum -= a[i][pos[i]];
                pos[i]++;
                sum += a[i][pos[i]];

                q.insert({ sum, pos });

                sum -= a[i][pos[i]];
                pos[i]--;
                sum += a[i][pos[i]];

                if (q.size() > n)
                    q.erase(--q.end());
            }
        }
    }

    return 1;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    while (solve());
}