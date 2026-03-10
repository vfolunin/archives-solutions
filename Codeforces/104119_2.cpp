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

    int a, b, c, d;
    cin >> a >> b >> c >> d;

    vector<pair<int, int>> pairs;
    if (a && b)
        pairs.push_back({ max(a, b) + 1, 1 });
    if (a && c)
        pairs.push_back({ b + 1, d + 1 });
    if (b && d)
        pairs.push_back({ a + 1, c + 1 });
    if (c && d)
        pairs.push_back({ 1, max(c, d) + 1 });

    sort(pairs.begin(), pairs.end(), [](auto &lhs, auto &rhs) {
        return lhs.first + lhs.second < rhs.first + rhs.second;
    });

    cout << pairs[0].first << " " << pairs[0].second;
}