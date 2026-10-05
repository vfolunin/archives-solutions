#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

void solve() {
    long long a, b, c;
    cin >> a >> b >> c;

    if (b % 3 && c < 3 - b % 3)
        cout << "-1\n";
    else
        cout << a + (b + c + 2) / 3 << "\n";
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int testCount;
    cin >> testCount;

    for (int test = 0; test < testCount; test++)
        solve();
}