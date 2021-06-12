#include <iostream>
#include <sstream>
#include <algorithm>
#include <cmath>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

struct Point {
    double x, y;
};

istream &operator >> (istream &in, Point &p) {
    in >> p.x >> p.y;
    return in;
}

double dist(Point &a, Point &b) {
    return hypot(a.x - b.x, a.y - b.y);
}

struct Graph {
    map<int, vector<pair<int, double>>> graph;

    void addEdge(vector<Point> &points, int a, int b, double speed) {
        double w = dist(points[a], points[b]) / speed;
        graph[a].push_back({ b, w });
        graph[b].push_back({ a, w });
    }

    double dijkstra() {
        vector<double> dist(graph.size(), 1e9);
        dist[0] = 0;
        set<pair<double, int>> q = { {dist[0], 0} };

        while (!q.empty()) {
            int v = q.begin()->second;
            q.erase(q.begin());

            for (auto &[to, w] : graph[v]) {
                if (dist[to] > dist[v] + w) {
                    q.erase({ dist[to], to });
                    dist[to] = dist[v] + w;
                    q.insert({ dist[to], to });
                }
            }
        }

        return dist[1];
    }
};

void solve(int test) {
    vector<Point> points(2);
    cin >> points[0] >> points[1];

    Graph graph;
    graph.addEdge(points, 0, 1, 10000);

    cin.ignore();
    while (1) {
        string line;
        getline(cin, line);

        if (line.empty())
            break;

        stringstream ss(line);
        int stationCount = 0;
        while (1) {
            Point p;
            ss >> p;

            if (p.x == -1 && p.y == -1)
                break;

            stationCount++;
            points.push_back(p);

            for (int from = 0; from < points.size() - 1; from++)
                graph.addEdge(points, from, points.size() - 1, 10000);
            if (stationCount > 1)
                graph.addEdge(points, points.size() - 2, points.size() - 1, 40000);
        }
    }

    if (test)
        cout << "\n";
    cout.precision(0);
    cout << fixed << graph.dijkstra() * 60 << "\n";
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int n;
    cin >> n;

    for (int i = 0; i < n; i++)
        solve(i);
}