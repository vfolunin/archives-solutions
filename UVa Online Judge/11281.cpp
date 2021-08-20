#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
#include <set>
#include <map>
#include <string>
using namespace std;

const double EPS = 1e-9;

bool isObtuse(double a, double b, double c) {
    return a * a + b * b + EPS < c *c || a * a + c * c + EPS < b * b || b * b + c * c + EPS < a * a;
}

double getExcircleR(double a, double b, double c) {
    double p = (a + b + c) / 2;
    return a * b * c / (4 * sqrt(p * (p - a) * (p - b) * (p - c)));
}

double getR(double a, double b, double c) {
    if (isObtuse(a, b, c))
        return max(a, max(b, c)) / 2;
    return getExcircleR(a, b, c);
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int holeCount;
    cin >> holeCount;

    vector<double> holeR(holeCount);
    for (double &r : holeR) {
        cin >> r;
        r /= 2;
    }

    int triangleCount;
    cin >> triangleCount;

    for (int i = 0; i < triangleCount; i++) {
        double a, b, c;
        cin >> a >> b >> c;

        double r = getR(a, b, c);

        vector<int> holes;
        for (int j = 0; j < holeCount; j++)
            if (r <= holeR[j] + EPS)
                holes.push_back(j);

        cout << "Peg " << (char)(i + 'A') << " will ";
        if (holes.empty()) {
            cout << "not fit into any holes\n";
        } else {
            cout << "fit into hole(s): ";
            for (int j = 0; j < holes.size(); j++)
                cout << holes[j] + 1 << (j + 1 < holes.size() ? " " : "\n");
        }
    }
}