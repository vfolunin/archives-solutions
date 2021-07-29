#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

struct Point {
    int x, y;

    Point() {}

    Point(const Point &a, const Point &b) : x(b.x - a.x), y(b.y - a.y) {}

    int crossProduct(const Point &that) const {
        return x * that.y - y * that.x;
    }

    bool isCollinearTo(const Point &that) const {
        return !crossProduct(that);
    }
};

int ones(int n) {
    int res = 0;
    while (n) {
        res++;
        n &= n - 1;
    }
    return res;
}

int rec(int mask, vector<Point> &trees, vector<int> &memo) {
    int &res = memo[mask];
    if (res != -1)
        return res;

    if (!mask)
        return res = 0;

    res = ones(mask);
    for (int a = 0; (1 << a) < mask; a++) {
        if (!(mask & (1 << a)))
            continue;

        for (int b = a + 1; (1 << b) < mask; b++) {
            if (!(mask & (1 << b)))
                continue;

            int nextMask = mask ^ (1 << a) ^ (1 << b);
            Point ab(trees[a], trees[b]);

            for (int c = 0; (1 << c) < mask; c++)
                if ((nextMask & (1 << c)) && ab.isCollinearTo(Point(trees[a], trees[c])))
                    nextMask ^= (1 << c);

            res = min(res, 1 + rec(nextMask, trees, memo));
        }
    }
    return res;
}

void solve(int test) {
    int treeCount, cutCount;
    cin >> treeCount >> cutCount;

    vector<Point> trees(treeCount);
    for (auto &[x, y] : trees)
        cin >> x >> y;

    vector<int> memo(1 << 16, -1);
    int res = cutCount;
    for (int mask = 0; mask < (1 << treeCount); mask++)
        if (ones(mask) == cutCount)
            res = min(res, rec(mask, trees, memo));

    if (test > 1)
        cout << "\n";
    cout << "Case #" << test << ":\n";
    cout << res << "\n";
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int n;
    cin >> n;

    for (int test = 1; test <= n; test++)
        solve(test);
}