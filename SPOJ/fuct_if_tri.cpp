#include <iostream>
#include <iomanip>
#include <algorithm>
#include <cmath>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

double perimeter(vector<double> &a) {
    return a[0] + a[1] + a[2];
}

double area(vector<double> &a) {
    double p = perimeter(a) / 2;
    return sqrt(p * (p - a[0]) * (p - a[1]) * (p - a[2]));
}

void solve() {
    vector<double> a(3);
    for (double &value : a)
        cin >> value;

    sort(a.begin(), a.end());

    if (a[0] < 1e-9)
        cout << "the length of triangular's edge must be greater than 0\n";
    else if (a[0] + a[1] <= a[2] + 1e-9)
        cout << "three numbers a and b and c cannot make a triangular\n";
    else
        cout << fixed << setprecision(0) << perimeter(a) << " " << setprecision(3) << area(a) << "\n";
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int testCount;
    cin >> testCount;

    for (int test = 0; test < testCount; test++)
        solve();
}