#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

bool solve(int test) {
    double imgW, imgH, wRatio, hRatio;
    cin >> imgW >> imgH >> wRatio >> hRatio;

    if (abs(imgW) < 1e-9 && abs(imgH) < 1e-9)
        return 0;

    int pointCount;
    cin >> pointCount;

    cout << "Case " << test << ":\n";
    for (int i = 0; i < pointCount; i++) {
        double x, y;
        cin >> x >> y;

        double h = imgH, w = imgW;
        bool black = 1;

        while (1) {
            double h1 = h * hRatio, h2 = h - h1;
            double w1 = w * wRatio, w2 = w - w1;

            if (y >= h1 && x <= w1 || y <= h1 && x >= w1) {
                cout << (black ? "black\n" : "white\n");
                break;
            }

            if (y < h1) {
                h = h1;
            } else {
                h = h2;
                y -= h1;
            }

            if (x < w1) {
                w = w1;
            } else {
                w = w2;
                x -= w1;
            }

            black ^= 1;
        }
    }
    return 1;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    ios_base::sync_with_stdio(0);
    cin.tie(0);

    for (int test = 1; solve(test); test++);
}