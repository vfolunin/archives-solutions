#include <iostream>
#include <sstream>
#include <algorithm>
#include <cmath>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <string>
using namespace std;

struct Point {
    double x, y;

    double distTo(const Point &that) const {
        return hypot(x - that.x, y - that.y);
    }
};

int bfs(vector<Point> &points, double limit) {
    vector<int> dist(points.size(), -1);
    queue<int> q;

    dist[0] = 0;
    q.push(0);

    while (!q.empty()) {
        int v = q.front();
        q.pop();

        for (int to = 0; to < points.size(); to++) {
            if (dist[to] == -1 && points[v].distTo(points[to]) <= limit + 1e-9) {
                dist[to] = dist[v] + 1;
                q.push(to);
            }
        }
    }

    return dist[1];
}

bool solve() {
    double velocity, time;
    cin >> velocity >> time;
    cin.ignore();

    if (!velocity && !time)
        return 0;

    double limit = velocity * time * 60;

    vector<Point> points;
    while (1) {
        string line;
        getline(cin, line);

        if (line.empty())
            break;

        stringstream ss(line);
        points.emplace_back();
        ss >> points.back().x >> points.back().y;
    }

    int dist = bfs(points, limit);

    if (dist != -1)
        cout << "Yes, visiting " << dist - 1 << " other holes.\n";
    else
        cout << "No.\n";
    return 1;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    while (solve());
}