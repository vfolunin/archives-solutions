#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

void solve() {
    int a, b, c, d;
    cin >> a >> b >> c >> d;

    a = min(a, c);
    b = min(b, d);

    cout << (a >= b ? "Gellyfish\n" : "Flower\n");
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int testCount;
    cin >> testCount;

    for (int test = 0; test < testCount; test++)
        solve();
}