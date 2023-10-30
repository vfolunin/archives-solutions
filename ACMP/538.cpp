#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

bool dfs(vector<pair<int, int>> &points, int v, vector<int> &visited, int color, double radius) {
    visited[v] = color;

    for (int to = 0; to < points.size(); to++) {
        if (to == v)
            continue;

        double dx = points[v].first - points[to].first;
        double dy = points[v].second - points[to].second;
        if (dx * dx + dy * dy > 4 * radius * radius)
            continue;

        if (!visited[to] && dfs(points, to, visited, 3 - color, radius))
            return 1;
        else if (visited[to] == color)
            return 1;
    }

    return 0;
}

bool can(vector<pair<int, int>> &points, vector<int> &visited, double radius) {
    fill(visited.begin(), visited.end(), 0);
    for (int v = 0; v < points.size(); v++)
        if (!visited[v] && dfs(points, v, visited, 1, radius))
            return 0;
    return 1;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int pointCount;
    cin >> pointCount;

    vector<pair<int, int>> points(pointCount);
    for (auto &[x, y] : points)
        cin >> x >> y;

    vector<int> visited(pointCount);

    double l = 0, r = 1e5;
    for (int i = 0; i < 100; i++) {
        double m = (l + r) / 2;
        if (can(points, visited, m))
            l = m;
        else
            r = m;
    }
    can(points, visited, l);

    cout.precision(10);
    cout << fixed << l << "\n";
    for (int color : visited)
        cout << color << " ";
}