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

    int width, size;
    cin >> width >> size;

    vector<pair<int, long long>> pairs(size);
    for (auto &[coord, count] : pairs)
        cin >> coord >> count;

    vector<long long> res(pairs.size());
    res[0] = pairs[0].first - 1 + pairs[0].second;

    for (int i = 1; i < res.size(); i++)
        res[i] = res[i - 1] + max(pairs[i].first - 1 - res[i - 1], 0LL) + pairs[i].second;

    cout << res.back();
}