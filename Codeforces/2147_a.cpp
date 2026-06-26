#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

void solve() {
    int x, y;
    cin >> x >> y;

    if (x < y)
        cout << "2\n";
    else if (y > 1 && x > y + 1)
        cout << "3\n";
    else
        cout << "-1\n";
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int testCount;
    cin >> testCount;

    for (int test = 0; test < testCount; test++)
        solve();
}