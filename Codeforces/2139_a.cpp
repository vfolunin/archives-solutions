#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

void solve() {
    int a, b;
    cin >> a >> b;

    if (a == b)
        cout << "0\n";
    else if (a % b == 0 || b % a == 0)
        cout << "1\n";
    else
        cout << "2\n";
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int testCount;
    cin >> testCount;

    for (int test = 0; test < testCount; test++)
        solve();
}