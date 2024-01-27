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

    for (double x, y; cin >> x >> y; )
        cout << fixed << x * x + sin(x * y) - y * y << "\n";
}