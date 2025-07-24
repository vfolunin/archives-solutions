#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
#include <numeric>
using namespace std;

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int size;
    cin >> size;

    vector<vector<int>> a(size, vector<int>(size));
    for (int y = 0; y < a.size(); y++)
        for (int x = 0; x < a.size(); x++)
            cin >> a[y][x];

    vector<int> order(a.size());
    iota(order.begin(), order.end(), 0);
    sort(order.begin(), order.end(), [&](int lhs, int rhs) {
        return accumulate(a[lhs].begin(), a[lhs].end(), 0) < accumulate(a[rhs].begin(), a[rhs].end(), 0);
    });

    long long res = 0;
    for (int i = 0; i < a.size() / 2; i++)
        for (int j = i + 1; j < a.size() / 2; j++)
            res -= a[order[i]][order[j]];
    for (int i = a.size() / 2; i < a.size(); i++)
        for (int j = i + 1; j < a.size(); j++)
            res += a[order[i]][order[j]];

    cout << res;
}