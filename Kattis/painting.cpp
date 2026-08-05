#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    double angle;
    cin >> angle;

    cout.precision(1);
    cout << fixed << tan(angle / 180 * acos(-1)) * 50;
}