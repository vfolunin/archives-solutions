struct Point {
    int x = 0, y = 0;

    Point() {}

    Point(int x, int y) : x(x), y(y) {}

    Point(Point &a, Point &b) : x(b.x - a.x), y(b.y - a.y) {}

    double distanceTo(Point &that) {
        return hypot(x - that.x, y - that.y);
    }

    int crossProduct(const Point &that) {
        return x * that.y - y * that.x;
    }

    friend ostream &operator << (ostream &out, Point &p) {
        return out << p.x << " " << p.y;
    }
};

struct Triangle {
    Point a, b, c;

    Triangle() {}

    Triangle(int ax, int ay, int bx, int by, int cx, int cy) :
        a(ax, ay), b(bx, by), c(cx, cy) {}
    
    void Out() {
        cout << a << " " << b << " " << c << "\n";
    }

    double area() {
        return abs(Point(a, b).crossProduct(Point(a, c))) / 2.0;
    }

    double perimeter() {
        return a.distanceTo(b) + a.distanceTo(c) + b.distanceTo(c);
    }

    double inscribedRadius() {
        return area() / (perimeter() / 2);
    }

    double describedRadius() {
        return a.distanceTo(b) * a.distanceTo(c) * b.distanceTo(c) / (area() * 4);
    }
};
