#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

long long gcd(long long a, long long b) {
    return b ? gcd(b, a % b) : a;
}

long long lcm(long long a, long long b) {
    return a / gcd(a, b) * b;
}

void solve() {
    int coordCount, offset;
    cin >> coordCount >> offset;

    vector<long long> coords(coordCount);
    for (long long &coord : coords) {
        cin >> coord;
        coord -= offset;
    }

    long long res = coords[0];
    for (int i = 1; i < coordCount; i++)
        res = lcm(res, coords[i]);
    
    cout << res << "\n";
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int n;
    cin >> n;

    for (int i = 0; i < n; i++)
        solve();
}