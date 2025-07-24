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

    double height, angle;
    cin >> height >> angle;

    double delta = sin(angle / 180 * acos(-1));
    if (delta < 0)
        cout << (int)(height / -delta);
    else
        cout << "safe";
}