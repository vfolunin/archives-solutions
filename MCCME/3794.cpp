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

    double px, py, ox, oy, r;
    cin >> px >> py >> ox >> oy >> r;

    cout << (hypot(px - ox, py - oy) <= r + 1e-9 ? "YES" : "NO");
}