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

    vector<pair<int, int>> points;
    for (int x, y; cin >> x >> y; )
        points.push_back({ x, y });

    sort(points.begin(), points.end(), [](auto &a, auto &b) {
        if (a.first != b.first)
            return a.first < b.first;
        return a.second > b.second;
    });

    for (auto &[x, y] : points)
        cout << x << " " << y << "\n";
}