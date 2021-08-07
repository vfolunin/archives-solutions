#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

struct DiophantineSolver {
    static int gcdex(int a, int b, int &x, int &y) {
        if (!b) {
            x = 1;
            y = 0;
            return a;
        }
        int x1, y1, d = gcdex(b, a % b, x1, y1);
        x = y1;
        y = x1 - a / b * y1;
        return d;
    }

    static bool solve(int a, int b, int c, int &x, int &y, int &d) {
        d = gcdex(abs(a), abs(b), x, y);
        if (c % d)
            return 0;
        x *= c / d * (a >= 0 ? 1 : -1);
        y *= c / d * (b >= 0 ? 1 : -1);
        return 1;
    }

    static void shift(int &x, int &y, int a, int b, int k) {
        x += k * b;
        y -= k * a;
    }

    static bool hasSolution(int a, int b, int c, int xl, int xr, int yl, int yr) {
        int x, y, d;
        if (!solve(a, b, c, x, y, d))
            return 0;
        a /= d;
        b /= d;

        int signA = a > 0 ? +1 : -1;
        int signB = b > 0 ? +1 : -1;

        shift(x, y, a, b, (xl - x) / b);
        if (x < xl)
            shift(x, y, a, b, signB);
        if (x > xr)
            return 0;
        int lx1 = x;

        shift(x, y, a, b, (xr - x) / b);
        if (x > xr)
            shift(x, y, a, b, -signB);
        int rx1 = x;

        shift(x, y, a, b, -(yl - y) / a);
        if (y < yl)
            shift(x, y, a, b, -signA);
        if (y > yr)
            return 0;
        int lx2 = x;

        shift(x, y, a, b, -(yr - y) / a);
        if (y > yr)
            shift(x, y, a, b, signA);
        int rx2 = x;

        if (lx2 > rx2)
            swap(lx2, rx2);
        int lx = max(lx1, lx2);
        int rx = min(rx1, rx2);

        return (rx - lx) / abs(b) + 1;
    }
};

bool connected(int base, int delta, int floor) {
    return base <= floor && (floor - base) % delta == 0;
}

bool connected(int base1, int delta1, int base2, int delta2, int floorCount) {
    int a = delta1, b = -delta2, c = base2 - base1;
    int xl = 0, xr = (floorCount - 1 - base1) / delta1;
    int yl = 0, yr = (floorCount - 1 - base2) / delta2;
    return DiophantineSolver::hasSolution(a, b, c, xl, xr, yl, yr);
}

void dfs(vector<vector<int>> &graph, int v, vector<int> &visited) {
    visited[v] = 1;
    for (int to : graph[v])
        if (!visited[to])
            dfs(graph, to, visited);
}

void solve() {
    int floorCount, elevatorCount, startFloor, finishFloor;
    cin >> floorCount >> elevatorCount >> startFloor >> finishFloor;

    vector<pair<int, int>> elevators(elevatorCount);
    for (auto &[base, delta] : elevators)
        cin >> delta >> base;

    vector<vector<int>> graph(1 + elevatorCount + 1);
    for (int i = 0; i < elevatorCount; i++) {
        if (connected(elevators[i].first, elevators[i].second, startFloor))
            graph[0].push_back(1 + i);
        if (connected(elevators[i].first, elevators[i].second, finishFloor))
            graph[1 + i].push_back(1 + elevatorCount);
    }
    for (int i = 0; i < elevatorCount; i++) {
        for (int j = i + 1; j < elevatorCount; j++) {
            if (connected(elevators[i].first, elevators[i].second, elevators[j].first, elevators[j].second, floorCount)) {
                graph[1 + i].push_back(1 + j);
                graph[1 + j].push_back(1 + i);
            }
        }
    }

    vector<int> visited(graph.size());
    dfs(graph, 0, visited);

    if (visited.back())
        cout << "It is possible to move the furniture.\n";
    else
        cout << "The furniture cannot be moved.\n";
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;

    for (int i = 0; i < n; i++)
        solve();
}