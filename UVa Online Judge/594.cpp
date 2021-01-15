#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

bool solve() {
    int n;
    if (!(cin >> n))
        return 0;

    int a = (n >> 24) & 255;
    int b = (n >> 16) & 255;
    int c = (n >> 8) & 255;
    int d = n & 255;
    int res = a | (b << 8) | (c << 16) | (d << 24);

    cout << n << " converts to " << res << "\n";
    return 1;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    while (solve());
}