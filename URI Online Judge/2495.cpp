#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

bool solve() {
    long long n;
    if (!(cin >> n))
        return 0;

    long long s = n * (n + 1) / 2;
    for (int i = 0; i < n - 1; i++) {
        int x;
        cin >> x;
        s -= x;
    }

    cout << s << "\n";
    return 1;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    ios_base::sync_with_stdio(0);
    cin.tie(0);

    while (solve());
}