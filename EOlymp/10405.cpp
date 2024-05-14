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

    int a, b, c, d;
    cin >> a >> b >> c >> d;

    int res = abs(a - b);
    res = min(res, abs(a - c) + abs(d - b));
    res = min(res, abs(a - d) + abs(c - b));

    cout << res;
}