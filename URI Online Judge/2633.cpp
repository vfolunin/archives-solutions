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

    vector<pair<int, string>> a(n);
    for (auto &[time, name] : a)
        cin >> name >> time;

    sort(a.begin(), a.end());

    for (int i = 0; i < n; i++)
        cout << a[i].second << (i + 1 < n ? " " : "\n");
    return 1;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    while (solve());
}