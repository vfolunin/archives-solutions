#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

bool solve() {
    int n, m;
    if (!(cin >> n >> m))
        return 0;

    vector<int> returned(n);
    for (int i = 0; i < m; i++) {
        int id;
        cin >> id;
        returned[id - 1] = 1;
    }

    for (int i = 0; i < n; i++)
        if (!returned[i])
            cout << i + 1 << " ";
    if (!count(returned.begin(), returned.end(), 0))
        cout << "*";
    cout << "\n";
    return 1;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    while (solve());
}