#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    double h, b;
    cin >> h >> b;

    cout.precision(10);
    cout << fixed << (b * b - h * h) / (2 * h);
}