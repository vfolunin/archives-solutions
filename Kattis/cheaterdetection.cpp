#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

void solve() {
    double doubleTime;
    cin >> doubleTime;

    int time = doubleTime * 1000 + 0.5;

    cout << (time % 15 == 0 || (time + 5) % 15 == 0 ? "VALID\n" : "IMPOSSIBLE\n");
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int n;
    cin >> n;

    for (int i = 0; i < n; i++)
        solve();
}