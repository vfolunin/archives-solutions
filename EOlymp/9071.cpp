struct Point {
    int x = 0, y = 0;

    Point() {}

    Point(int x, int y) : x(x), y(y) {}

    Point(Point &a, Point &b) : x(b.x - a.x), y(b.y - a.y) {}

    long long dist2To(Point &that) {
        long long dx = x - that.x;
        long long dy = y - that.y;
        return dx * dx + dy * dy;
    }

    friend ostream &operator << (ostream &out, Point &p) {
        return out << p.x << " " << p.y;
    }
};

struct Triangle {
    Point a, b, c;
    vector<long long> sides2;

    Triangle() {}

    Triangle(int ax, int ay, int bx, int by, int cx, int cy) :
        a(ax, ay), b(bx, by), c(cx, cy) {
        sides2 = { a.dist2To(b), a.dist2To(c), b.dist2To(c) };
        sort(sides2.begin(), sides2.end());
    }
    
    void Out() {
        cout << a << " " << b << " " << c << "\n";
    }

    bool equilateral() {
        return sides2[0] == sides2[2];
    }

    bool isosceles() {
        return sides2[0] == sides2[1] || sides2[1] == sides2[2];
    }

    bool versatile() {
        return sides2[0] != sides2[1] && sides2[1] != sides2[2];
    }

    bool rectangular() {
        return sides2[0] + sides2[1] == sides2[2];
    }

    bool acute_angled() {
        return sides2[0] + sides2[1] > sides2[2];
    }

    bool obtuse() {
        return sides2[0] + sides2[1] < sides2[2];
    }
};
