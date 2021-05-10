#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

void solve(int test) {
    int segmentCount;
    cin >> segmentCount;

    set<pair<double, double>> events;
    for (int i = 0; i < segmentCount; i++) {
        double x1, y1, x2, y2, t;
        cin >> x1 >> y1 >> x2 >> y2 >> t;
        if (x1 > x2)
            swap(x1, x2);
        events.insert({ x1, t });
        events.insert({ x2, 1 / t });
    }

    vector<vector<double>> res;
    double prevX = -1e100, t = 1;
    for (auto &[x, dt] : events) {
        res.push_back({ prevX, x, t });
        t *= dt;
        prevX = x;
    }
    res.push_back({ prevX, 1e100, t });

    if (test)
        cout << "\n";
    cout << res.size() << "\n";
    cout.precision(3);
    for (vector<double> &r : res) {
        cout << fixed;
        if (r[0] == -1e100)
            cout << "-inf";
        else
            cout << r[0];
        cout << " ";
        if (r[1] == 1e100)
            cout << "+inf";
        else
            cout << r[1];
        cout << " " << r[2] << "\n";
    }
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int n;
    cin >> n;

    for (int i = 0; i < n; i++)
        solve(i);
}