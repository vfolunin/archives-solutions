#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

struct Color {
    int r, g, b;

    int getDiff(const Color &that) const {
        return abs(r - that.r) + abs(g - that.g) + abs(b - that.b);
    }

    friend istream &operator >> (istream &in, Color &color) {
        return in >> color.r >> color.g >> color.b;
    }
};

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    string mode;
    Color backColor, fontColor;
    cin >> mode >> backColor >> fontColor;

    int score = mode == "monospace";
    score += backColor.getDiff({ 0, 0, 0 }) <= 25;
    score += fontColor.getDiff({ 0, 255, 0 }) <= 35;

    cout << (score >= 2 ? "L33T H4X0R" : "n00b");
}