class Vector {
    int x = 0, y = 0, z = 0;

public:
    Vector() {}

    Vector(int x, int y, int z) : x(x), y(y), z(z) {}

    void setX(int x) {
        this->x = x;
    }

    void setY(int y) {
        this->y = y;
    }

    void setZ(int z) {
        this->z = z;
    }

    int getX() {
        return x;
    }

    int getY() {
        return y;
    }

    int getZ() {
        return z;
    }

    double length() {
        return hypot(x, y, z);
    }

    void Out() {
        cout << x << " " << y << " " << z << "\n";
    }
};