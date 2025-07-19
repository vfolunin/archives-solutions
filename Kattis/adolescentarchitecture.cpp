#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

struct Shape {
    string type;
    int size;

    double area() const {
        if (type == "cube")
            return size * size;
        else
            return acos(-1) * size * size;
    }

    bool operator < (const Shape &that) const {
        return area() < that.area();
    }

    bool fitsIn(const Shape &that) const {
        if (type == that.type)
            return size <= that.size;
        else if (type == "cube")
            return size * sqrt(2) / 2 <= that.size;
        else
            return size * 2 <= that.size;
    }

    friend istream &operator >> (istream &in, Shape &shape) {
        return in >> shape.type >> shape.size;
    }

    friend ostream &operator << (ostream &out, Shape &shape) {
        return out << shape.type << " " << shape.size;
    }
};

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int shapeCount;
    cin >> shapeCount;

    vector<Shape> shapes(shapeCount);
    for (Shape &shape : shapes)
        cin >> shape;

    sort(shapes.begin(), shapes.end());

    for (int i = 0; i + 1 < shapes.size(); i++) {
        if (!shapes[i].fitsIn(shapes[i + 1])) {
            cout << "impossible";
            return 0;
        }
    }

    for (Shape &shape : shapes)
        cout << shape << "\n";
}