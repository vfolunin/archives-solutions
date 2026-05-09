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

    int a, b, delta;
    cin >> a >> b >> delta;

    if (delta)
        cout << ((b - a) % delta == 0 && (b - a) / delta >= 0 ? "YES" : "NO");
    else
        cout << (a == b ? "YES" : "NO");
}