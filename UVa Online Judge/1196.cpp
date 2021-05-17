#include <iostream>
#include <iomanip>
#include <algorithm>
#include <cmath>
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

    vector<pair<int, int>> p(n);
    for (auto &[a, b] : p)
        cin >> a >> b;
    sort(p.begin(), p.end());

    vector<int> minLast(n + 1, 1e9);
    minLast[0] = -1e9;
    for (auto &[_, x] : p)
        *upper_bound(minLast.begin(), minLast.end(), x) = x;
    
    int res = n;
    while (minLast[res] == 1e9)
        res--;

    cout << res << "\n";
    return 1;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    while (solve());
    cout << "*\n";
}