#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

struct Rectangle {
    long long x1, y1, x2, y2;

    long long area() {
        return max(x2 - x1, 0LL) * max(y2 - y1, 0LL);
    }

    Rectangle intersect(Rectangle &that) {
        return { max(x1, that.x1), max(y1, that.y1), min(x2, that.x2), min(y2, that.y2) };
    }

    friend istream &operator >> (istream &in, Rectangle &r) {
        in >> r.x1 >> r.y1 >> r.x2 >> r.y2;
        if (r.x1 > r.x2)
            swap(r.x1, r.x2);
        if (r.y1 > r.y2)
            swap(r.y1, r.y2);
        return in;
    }
};

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    Rectangle a, b, c;
    cin >> a >> b >> c;

    long long res = a.area() + b.area() + c.area();
    res -= a.intersect(b).area() + a.intersect(c).area() + b.intersect(c).area();
    res += a.intersect(b).intersect(c).area();

    cout << res;
}