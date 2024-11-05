struct Vector {
    double x, y;

    Vector(double x = 0, double y = 0) : x(x), y(y) {}

    void Input() {
        cin >> x >> y;
    }

    void Out() {
        cout << x << " " << y << "\n";
    }

    Vector &operator += (const Vector &that) {
        x += that.x;
        y += that.y;
        return *this;
    }

    Vector &operator -= (const Vector &that) {
        x -= that.x;
        y -= that.y;
        return *this;
    }

    Vector operator + (const Vector &that) const {
        Vector res = *this;
        res += that;
        return res;
    }

    Vector operator - (const Vector &that) const {
        Vector res = *this;
        res -= that;
        return res;
    }

    double operator * (const Vector &that) const {
        return x * that.x + y * that.y;
    }
};

