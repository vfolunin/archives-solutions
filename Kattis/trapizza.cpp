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

    double d, a, b, h;
    cin >> d >> a >> b >> h;

    double area1 = acos(-1) * d * d / 4;
    double area2 = (a + b) * h / 2;

    if (abs(area1 - area2) < 1e-9)
        cout << "Jafn storar!";
    else if (area1 > area2)
        cout << "Mahjong!";
    else
        cout << "Trapizza!";
}