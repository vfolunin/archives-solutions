#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

int rec(long long n, long long y, long long x) {
    if (n == 1)
        return 1;
    long long half = n / 2;
    return (y >= half && x >= half ? -1 : 1) * rec(n / 2, y % half, x % half);
}

void solve() {
    long long n, fromX, fromY, w, h;
    cin >> n >> fromX >> fromY >> w >> h;

    for (long long y = 0; y < h; y++) {
        for (long long x = 0; x < w; x++)
            cout << rec(n, fromY + y, fromX + x) << " ";
        cout << "\n";
    }
    cout << "\n";
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int n;
    cin >> n;

    for (int i = 0; i < n; i++)
        solve();
}