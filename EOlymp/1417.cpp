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

    int h, w, y, x;
    cin >> h >> w >> y >> x;
    y--;
    x--;

    long long res = h - 1 + w - 1;
    res += min(y, x);
    res += min(y, w - 1 - x);
    res += min(h - y - 1, x);
    res += min(h - y - 1, w - 1 - x);

    cout << res;
}