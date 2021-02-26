#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

bool solve() {
    int n;
    cin >> n;

    if (!n)
        return 0;

    vector<vector<long long>> a(1, vector<long long>(n));
    for (long long &x : a[0])
        cin >> x;

    for (int i = 1; i < n; i++) {
        a.emplace_back();
        for (int j = 1; j < a[i - 1].size(); j++)
            a.back().push_back(a[i - 1][j] - a[i - 1][j - 1]);
    }

    int k;
    cin >> k;

    for (int i = 0; i < k; i++) {
        a.back().push_back(a.back()[0]);
        for (int j = a.size() - 2; j >= 0; j--)
            a[j].push_back(a[j].back() + a[j + 1][a[j].size() - 1]);
    }

    cout << "Term " << n + k << " of the sequence is " << a[0].back() << "\n";
    return 1;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    while (solve());
}