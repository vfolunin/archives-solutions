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

    int cx, cy, radius, x, y;
    cin >> cx >> cy >> radius >> x >> y;

    cout << ((cx - x) * (cx - x) + (cy - y) * (cy - y) <= radius * radius ? "YES" : "NO");
}