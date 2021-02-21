#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

const double EPS = 1e-9;

double solveEquation(double a, double b, double c) {
    double d = b * b - 4 * a * c;
    double x1 = (-b - sqrt(d)) / (2 * a);
    double x2 = (-b + sqrt(d)) / (2 * a);
    return min(x1, x2);
}

bool solve() {
    double w, h, v, angle, t;
    cin >> w >> h >> v >> angle >> t;

    if (!w && !h)
        return 0;

    double x = w / 2;
    double y = h / 2;
    double vx = v * cos(angle / 180 * acos(-1));
    double vy = v * sin(angle / 180 * acos(-1));
    double ax = -v / t * cos(angle / 180 * acos(-1));
    double ay = -v / t * sin(angle / 180 * acos(-1));

    int collisionsX = 0, collisionsY = 0;
    double curT = 0;
    while (1) {
        double collT = 1e9;
        if (vx < -EPS)
            collT = min(collT, solveEquation(ax / 2, vx, x));
        if (vx > EPS)
            collT = min(collT, solveEquation(ax / 2, vx, x - w));
        if (vy < -EPS)
            collT = min(collT, solveEquation(ay / 2, vy, y));
        if (vy > EPS)
            collT = min(collT, solveEquation(ay / 2, vy, y - h));

        if (curT + collT > t)
            break;

        x += vx * collT + ax * collT * collT / 2;
        y += vy * collT + ay * collT * collT / 2;
        vx += ax * collT;
        vy += ay * collT;
        curT += collT;

        if (fabs(x) < EPS || fabs(x - w) < EPS) {
            collisionsX++;
            vx = -vx;
            ax = -ax;
        }
        if (fabs(y) < 1e-9 || fabs(y - h) < 1e-9) {
            collisionsY++;
            vy = -vy;
            ay = -ay;
        }
    }

    cout << collisionsX << " " << collisionsY << "\n";
    return 1;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    while (solve());
}