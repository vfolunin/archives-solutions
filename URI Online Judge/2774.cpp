#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

bool solve() {
    int h, m;
    if (!(cin >> h >> m))
        return 0;

    int size = h * 60 / m;
    vector<double> a(size);
    double average = 0;
    for (double &x : a) {
        cin >> x;
        average += x;
    }
    average /= size;

    double squareSum = 0;
    for (double &x : a)
        squareSum += (x - average) * (x - average);

    double sigma = sqrt(squareSum / (size - 1));

    cout.precision(5);
    cout << fixed << sigma << "\n";
    return 1;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    while (solve());
}