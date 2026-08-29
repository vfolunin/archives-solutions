#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

double p(double r, double sigma) {
    return exp(-r * r / (2 * sigma * sigma));
}

double p(double r1, double r2, double sigma) {
    return p(r1, sigma) - p(r2, sigma);
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    vector<double> r(7);
    for (int i = 1; i < r.size(); i++)
        cin >> r[i];

    double sigma;
    cin >> sigma;

    vector<double> points = { 50, 25, 10.5, 31.5, 10.5, 21 };
    double score = 0;
    for (int i = 0; i < points.size(); i++)
        score += p(r[i], r[i + 1], sigma) * points[i];

    cout.precision(10);
    cout << score << "\n";
}