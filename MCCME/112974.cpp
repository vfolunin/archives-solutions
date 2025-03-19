#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

int main() {
    freopen("g.in", "r", stdin);
    freopen("g.out", "w", stdout);

    double s, v1, v2;
    cin >> s >> v1 >> v2;

    double t = s / (v1 + v2);

    cout << fixed << v1 * t;
}