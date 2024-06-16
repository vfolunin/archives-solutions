#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

void solve() {
    int test;
    double distance, v1, v2, v3;
    cin >> test >> distance >> v1 >> v2 >> v3;

    cout.precision(2);
    cout << test << " " << fixed << distance / (v1 + v2) * v3 << "\n";
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int n;
    cin >> n;

    for (int i = 0; i < n; i++)
        solve();
}