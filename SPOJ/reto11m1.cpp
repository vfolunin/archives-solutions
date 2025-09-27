#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

bool solve() {
    vector<int> a(3);
    cin >> a[0] >> a[1] >> a[2];
    sort(a.begin(), a.end());

    if (!a[2])
        return 0;

    cout << (a[0] * a[0] + a[1] * a[1] == a[2] * a[2] ? "right\n" : "wrong\n");
    return 1;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    while (solve());
}