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

    double radius, h, w;
    cin >> radius >> h >> w;

    cout << (radius >= hypot(h, w) / 2 ? "YES" : "NO");
}