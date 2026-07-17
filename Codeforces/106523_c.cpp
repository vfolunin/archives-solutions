#include <iostream>
#include <cmath>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    double h, w, l;
    cin >> h >> w >> l;

    double num = 1.5 * sqrt(3) * l * l;
    double den = h * w;

    cout << fixed << num / den;
}