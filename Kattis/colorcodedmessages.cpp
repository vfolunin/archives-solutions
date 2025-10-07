#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

struct Color {
    int r, g, b;

    bool operator < (const Color &that) const {
        return vector{ r, g, b } < vector{that.r, that.g, that.b};
    }

    bool isCloseTo(const Color &that) const {
        return abs(r - that.r) + abs(g - that.g) + abs(b - that.b) < 25;
    }

    friend istream &operator >> (istream &in, Color &color) {
        return in >> color.r >> color.g >> color.b;
    }
};

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    map<Color, char> codes = {
        { { 255, 255, 255 }, 'w' },
        { { 0, 0, 255 }, 'b' },
        { { 255, 0, 255 }, 'f' },
        { { 255, 165, 0 }, 'o' },
        { { 18, 10, 143 }, 'u' },
        { { 220, 20, 60 }, 'c' },
        { { 255, 0, 0 }, 'r' },
        { { 255, 255, 0 }, 'y' },
        { { 192, 192, 192 }, 's' },
        { { 75, 0, 130 }, 'i' },
        { { 165, 42, 42 }, 'h' },
        { { 0, 255, 0 }, 'g' },
        { { 0, 255, 255 }, 'a' },
        { { 128, 0, 0 }, 'm' },
        { { 80, 200, 120 }, 'e' },
        { { 255, 192, 203 }, 'p' },
        { { 0, 0, 0 }, ' ' }
    };

    int size;
    cin >> size;

    for (int i = 0; i < size; i++) {
        Color color;
        cin >> color;

        for (auto &[codeColor, c] : codes) {
            if (color.isCloseTo(codeColor)) {
                cout << c;
                break;
            }
        }
    }
    cout << "\n";
}