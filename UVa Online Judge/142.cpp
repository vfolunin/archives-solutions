#include <iostream>
#include <iomanip>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

struct Point {
    int x, y;

    int dist2To(const Point &that) const {
        int dx = x - that.x, dy = y - that.y;
        return dx * dx + dy * dy;
    }
};

struct Rect {
    Point l, r;

    bool has(const Point &p) const {
        return l.x <= p.x && p.x <= r.x && l.y <= p.y && p.y <= r.y;
    }
};

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    vector<Point> points;
    vector<Rect> rects;
    vector<bool> visible;
    
    while (1) {
        char c;
        cin >> c;

        if (c == 'I') {
            Point p;
            cin >> p.x >> p.y;
            
            points.push_back(p);
            visible.push_back(1);

            for (Rect &r : rects)
                if (r.has(p))
                    visible.back() = 0;
        }

        if (c == 'R') {
            Rect r;
            cin >> r.l.x >> r.l.y >> r.r.x >> r.r.y;

            rects.push_back(r);

            for (int i = 0; i < points.size(); i++)
                if (r.has(points[i]))
                    visible[i] = 0;
        }

        if (c == 'M') {
            Point p;
            cin >> p.x >> p.y;

            bool found = 0;
            for (int i = (int)rects.size() - 1; i >= 0; i--) {
                if (rects[i].has(p)) {
                    cout << (char)('A' + i) << "\n";
                    found = 1;
                    break;
                }
            }

            if (found)
                continue;

            int minDist = 1e9;
            vector<int> pids;

            for (int i = 0; i < points.size(); i++) {
                if (!visible[i])
                    continue;
                int curDist = p.dist2To(points[i]);
                if (curDist < minDist) {
                    minDist = curDist;
                    pids.clear();
                }
                if (curDist == minDist)
                    pids.push_back(i + 1);
            }

            for (int pid : pids)
                cout << setw(3) << pid;
            cout << "\n";
        }

        if (c == '#')
            break;
    }
}