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

    double g, a, b;
    cin >> g >> a >> b;

    if (g > 50 && g * 1.5 >= a && (g * 1.5 < b || a <= b))
        cout << "A";
    else if (g > 50 && g * 1.5 >= b)
        cout << "B";
    else
        cout << "X";
}