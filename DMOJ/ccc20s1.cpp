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

    vector<pair<int, int>> a(size);
    for (auto &[time, coord] : a)
        cin >> time >> coord;

    sort(a.begin(), a.end());

    double res = 0;
    for (int i = 0; i + 1 < a.size(); i++)
        res = max(res, (double)abs(a[i + 1].second - a[i].second) / (a[i + 1].first - a[i].first));

    cout << fixed << res;
}