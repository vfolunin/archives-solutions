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
    int size;
    cin >> size;

    if (!size)
        return 0;

    vector<pair<int, int>> a(size);
    for (auto &[h, w] : a)
        cin >> h >> w;

    vector<vector<long long>> minOps(size, vector<long long>(size));
    vector<vector<int>> divAfter(size, vector<int>(size));

    for (int length = 2; length <= size; length++) {
        for (int l = 0, r = l + length - 1; r < size; l++, r++) {
            minOps[l][r] = 1e18;
            for (int m = l; m < r; m++) {
                long long ops = minOps[l][m] + minOps[m + 1][r] + 1LL * a[l].first * a[m].second * a[r].second;
                if (ops < minOps[l][r]) {
                    minOps[l][r] = ops;
                    divAfter[l][r] = m;
                }
            }
        }
    }

    cout << "Case " << test << ": ";
    print(divAfter, 0, size - 1);
    cout << "\n";
    return 1;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    for (int test = 1; solve(test); test++);
}