#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

struct Slope {
    long long x, y;

    bool operator < (const Slope &that) const {
        return x * that.y < y * that.x;
    }
};

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int pointCount;
    cin >> pointCount;

    map<int, set<Slope>> slopes;
    for (int i = 0; i < pointCount; i++) {
        int x, y;
        cin >> x >> y;
        slopes[x].insert({ x, y });
    }

    set<Slope> res;
    for (auto &[x, slopes] : slopes)
        res.insert(*slopes.begin());

    cout << res.size();
}