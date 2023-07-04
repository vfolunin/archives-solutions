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

    double h, w, t, v1, v2;
    cin >> h >> w >> t >> v1 >> v2;

    cout << fixed << min((w + t * v2) / (v1 + v2) + h / v1, (w + h) / v1);
}