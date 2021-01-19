#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

void print(vector<vector<int>> &divAfter, int l, int r) {
    if (l == r) {
        cout << "A" << (l + 1);
        return;
    }
    int m = divAfter[l][r];
    cout << "(";
    print(divAfter, l, m);
    cout << " x ";
    print(divAfter, m + 1, r);
    cout << ")";
}

bool solve(int test) {
    int n;
    cin >> n;

    if (!n)
        return 0;

    vector<pair<int, int>> a(n);
    for (auto &[h, w] : a)
        cin >> h >> w;

    vector<vector<int>> minOps(n, vector<int>(n));
    vector<vector<int>> divAfter(n, vector<int>(n));

    for (int length = 2; length <= n; length++) {
        for (int l = 0, r = l + length - 1; r < n; l++, r++) {
            minOps[l][r] = 1e9;
            for (int m = l; m < r; m++) {
                int ops = minOps[l][m] + minOps[m + 1][r] + a[l].first * a[m].second * a[r].second;
                if (ops < minOps[l][r]) {
                    minOps[l][r] = ops;
                    divAfter[l][r] = m;
                }
            }
        }
    }

    cout << "Case " << test << ": ";
    print(divAfter, 0, n - 1);
    cout << "\n";
    return 1;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    for (int test = 1; solve(test); test++);
}