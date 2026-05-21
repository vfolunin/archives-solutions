#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

void solve() {
    int target, sell, buy;
    cin >> target >> sell >> buy;

    if (sell <= buy)
        cout << (target + sell - 1) / sell << "\n";
    else
        cout << "1\n";
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int testCount;
    cin >> testCount;

    for (int test = 0; test < testCount; test++)
        solve();
}