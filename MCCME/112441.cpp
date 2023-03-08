#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int size;
    cin >> size;

    vector<vector<int>> a(2);
    for (int i = 0; i < size; i++) {
        int value;
        cin >> value;
        a[value % 2].push_back(value);
    }

    for (vector<int> &a : a)
        sort(a.begin(), a.end());

    int res = 1e9;
    if (a[0].size() >= 2)
        res = min(res, a[0][0] + a[0][1]);
    if (a[1].size() >= 2)
        res = min(res, a[1][0] + a[1][1]);
    if (res == 1e9)
        res = a[0][0] + a[1][0];

    cout << res;
}