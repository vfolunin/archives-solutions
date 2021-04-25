#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

void solve(int test) {
    vector<int> a(4), b(4);
    cin >> a[0] >> a[1] >> a[3] >> a[2];
    cin >> b[0] >> b[1] >> b[3] >> b[2];

    cout << "Case #" << test << ": ";
    for (int i = 0; i < 4; i++) {
        if (a == b) {
            cout << "POSSIBLE\n";
            return;
        }
        rotate(a.begin(), a.begin() + 1, a.end());
    }
    cout << "IMPOSSIBLE\n";
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int n;
    cin >> n;

    for (int test = 1; test <= n; test++)
        solve(test);
}