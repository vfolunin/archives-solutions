#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

void solve() {
    string s;
    int d;
    cin >> s >> d;

    sort(s.begin(), s.end());

    int res = 0;
    do {
        res += stoll(s) % d == 0;
    } while (next_permutation(s.begin(), s.end()));

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