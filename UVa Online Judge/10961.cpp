#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

struct Point {
    int x, y;

    bool operator == (const Point &that) const {
        return x == that.x && y == that.y;
    }

    bool moveTo(const Point &that) {
        if (x != that.x)
            x += (x < that.x ? 1 : -1);
        else
            y += (y < that.y ? 1 : -1);
        return *this == that;
    }
};

void solve(int test) {
    Point ap, bp;
    cin >> bp.x >> bp.y;
    cin >> ap.x >> ap.y;

    int aSize;
    cin >> aSize;

    vector<Point> a(aSize);
    for (auto &[x, y] : a)
        cin >> x >> y;

    int bSize;
    cin >> bSize;

    vector<Point> b(bSize);
    for (auto &[x, y] : b)
        cin >> x >> y;

    if (test)
        cout << "\n";

    for (int ai = 0, bi = 0; ai < aSize && bi < bSize; ai += ap.moveTo(a[ai]), bi += bp.moveTo(b[bi])) {
        if (ap == bp) {
            cout << "No\n";
            return;
        }
    }
    cout << "Yes\n";
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int n;
    cin >> n;

    for (int i = 0; i < n; i++)
        solve(i);
}