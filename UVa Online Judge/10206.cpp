#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

const double EPS = 1e-9;

struct Point {
    double x, y;

    Point(double x = 0, double y = 0) : x(x), y(y) {}

    bool operator == (const Point &that) const {
        return fabs(x - that.x) < EPS && fabs(y - that.y) < EPS;
    }

    bool operator < (const Point &that) const {
        return x + EPS < that.x || fabs(x - that.x) < EPS && y + EPS < that.y;
    }

    double length() const {
        return hypot(x, y);
    }

    double angle() const {
        double a = atan2(y, x);
        if (a < 0)
            a += 2 * acos(-1.0);
        return a;
    }

    Point operator + (const Point &that) const {
        return Point(x + that.x, y + that.y);
    }

    Point operator - (const Point &that) const {
        return Point(x - that.x, y - that.y);
    }
};

struct Transformation {
    double scale;
    double rotation;

    Transformation(const Point &a, const Point &b) {
        scale = b.length() / a.length();
        rotation = b.angle() - a.angle();
    }

    Point apply(const Point &p) const {
        double x = p.x * cos(rotation) - p.y * sin(rotation);
        double y = p.x * sin(rotation) + p.y * cos(rotation);
        return Point(x * scale, y * scale);
    }
};

struct Constellation {
    string name;
    vector<Point> deltas;
};

istream &operator >> (istream &in, Constellation &c) {
    int starCount;
    Point firstStar;
    in >> starCount >> c.name >> firstStar.x >> firstStar.y;
    for (int i = 1; i < starCount; i++) {
        Point star;
        in >> star.x >> star.y;
        c.deltas.push_back(star - firstStar);
    }
    return in;
}

struct Star {
    Point coords;
    int brightness;
};

istream &operator >> (istream &in, Star &s) {
    in >> s.coords.x >> s.coords.y >> s.brightness;
    return in;
}

struct StarMap {
    map<Point, int> stars;
    map<set<Point>, int> occurences;

    void add(const Star &s) {
        stars[s.coords] = s.brightness;
    }

    void searchST(const Constellation &c, const Point &s, const Transformation &t) {
        set<Point> coords = { s };
        int brightness = stars.at(s);
        for (const Point &d : c.deltas) {
            Point p = s + t.apply(d);
            if (!stars.count(p))
                return;
            coords.insert(p);
            brightness += stars.at(p);
        }        
        occurences[coords] = brightness;
    }

    pair<int, set<Point>> getAnswer() const {
        if (occurences.empty())
            return { 0, {} };
        auto bestIt = occurences.begin();
        for (auto it = occurences.begin(); it != occurences.end(); it++)
            if (it->second > bestIt->second)
                bestIt = it;
        return { occurences.size(), bestIt->first };
    }

    pair<int, set<Point>> search(const Constellation &c) {
        occurences.clear();
        if (c.deltas.empty()) {
            for (const auto &[s, b] : stars)
                occurences[{ s }] = b;
        } else {
            for (const auto &[s1, _] : stars) {
                for (const auto &[s2, _] : stars) {
                    if (s1 == s2)
                        continue;
                    Transformation t(c.deltas[0], s2 - s1);
                    searchST(c, s1, t);
                }
            }
        }
        return getAnswer();        
    }
};

bool solve(int test) {
    int starCount;
    cin >> starCount;

    if (!starCount)
        return 0;

    StarMap starMap;
    for (int i = 0; i < starCount; i++) {
        Star star;
        cin >> star;
        starMap.add(star);
    }

    int constellationCount;
    cin >> constellationCount;

    cout << "Map #" << test << "\n";

    for (int i = 0; i < constellationCount; i++) {
        Constellation constellation;
        cin >> constellation;
        auto [occurences, coords] = starMap.search(constellation);

        cout << "\n" << constellation.name << " occurs " << occurences << " time(s) in the map.\n";
        if (occurences) {
            cout << "Brightest occurrence:";            
            for (const Point &coords : coords)
                cout << " (" << coords.x << "," << coords.y << ")";
            cout << "\n";
        }        
    }

    cout << "-----\n";    
    return 1;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    cout.precision(0);
    cout << fixed;
    for (int test = 1; solve(test); test++);
}