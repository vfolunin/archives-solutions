#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

void solve() {
    int n;
    cin >> n;

    if (n == 2)
        cout << "2\n";
    else
        cout << n % 2 << "\n";
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int testCount;
    cin >> testCount;

    for (int test = 0; test < testCount; test++)
        solve();
}