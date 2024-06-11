#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

struct Rectangle {
    int y1, x1, y2, x2;

    bool has(int y, int x) {
        return y1 <= y && y < y2 && x1 <= x && x < x2;
    }

    friend istream &operator >> (istream &in, Rectangle &r) {
        in >> r.y1 >> r.x1 >> r.y2 >> r.x2;
        if (r.y1 > r.y2)
            swap(r.y1, r.y2);
        if (r.x1 > r.x2)
            swap(r.x1, r.x2);
        return in;
    }
};

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    Rectangle a, b, c;
    cin >> a >> b >> c;

    int res = 0;
    for (int y = -100; y <= 100; y++)
        for (int x = -100; x <= 100; x++)
            res += a.has(y, x) || b.has(y, x) || c.has(y, x);

    cout << res;
}