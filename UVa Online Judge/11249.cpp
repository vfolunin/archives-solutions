#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

vector<int> prepare(int maxDiff) {
    vector<int> pair(100001, -1);

    pair[1] = maxDiff + 2;
    pair[maxDiff + 2] = 1;

    for (int i = 2, j = 1; i < pair.size(); i++) {
        if (pair[i] != -1)
            continue;

        int p = pair[j] - j + i + maxDiff + 1;
        if (p < pair.size()) {
            j = i;
            pair[i] = p;
            pair[p] = i;
        }
    }

    return pair;
}

void solve() {
    int maxDiff, n;
    cin >> maxDiff >> n;

    vector<int> pair = prepare(maxDiff);

    for (int i = 0; i < n; i++) {
        int a, b;
        cin >> a >> b;
        cout << (pair[a] != b ? "WINNING\n" : "LOSING\n");
    }
    cout << "\n";
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int n;
    cin >> n;

    for (int i = 0; i < n; i++)
        solve();
}