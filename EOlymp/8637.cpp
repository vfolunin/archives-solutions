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
        if (a.first + a.second != b.first + b.second)
            return a.first + a.second < b.first + b.second;
        return a.first < b.first;
    });

    for (auto &[x, y] : points)
        cout << x << " " << y << "\n";
}