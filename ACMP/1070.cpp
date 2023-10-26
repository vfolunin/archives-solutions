#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

double f(double a, double b, double c, double x) {
    return a * x * x + b * x + c;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int size;
    cin >> size;

    double sum = 0;
    vector<double> xs;

    for (int i = 0; i < size; i++) {
        double l, r, a, b, c;
        cin >> l >> r >> a >> b >> c;

        for (int j = 0; j < 100; j++) {
            double m1 = l + (r - l) / 3;
            double m2 = r - (r - l) / 3;
            if (f(a, b, c, m1) < f(a, b, c, m2))
                r = m2;
            else
                l = m1;
        }

        sum += f(a, b, c, l);
        xs.push_back(l);
    }

    cout << fixed << sum << "\n";
    for (double x : xs)
        cout << fixed << x << " ";
}