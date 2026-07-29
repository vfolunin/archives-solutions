#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

void solve() {
    long long a, b;
    cin >> a >> b;

    cout << a * b << "\n";
}

int main() {
    freopen("window.in", "r", stdin);

    int testCount;
    cin >> testCount;

    for (int test = 0; test < testCount; test++)
        solve();
}