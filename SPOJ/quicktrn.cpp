#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

void solve() {
    int sum;
    cin >> sum;

    int res = 0;
    for (int nominal : { 1000, 500, 100, 50, 20, 10, 5, 2, 1 }) {
        res += sum / nominal;
        sum %= nominal;
    }

    cout << res << "\n";
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int n;
    cin >> n;

    for (int i = 0; i < n; i++)
        solve();
}