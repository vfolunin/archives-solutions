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

    vector<pair<int, int>> pairs(size);
    for (auto &[a, b] : pairs)
        cin >> a >> b;

    sort(pairs.begin(), pairs.end());

    int res = -1e9;
    for (auto &[a, b] : pairs)
        res = max(res, a) + b;

    cout << res;
}