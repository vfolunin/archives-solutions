#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

void solve() {
    int size;
    cin >> size;

    vector<int> count(1 << 10);
    for (int i = 0; i < size; i++) {
        string s;
        cin >> s;

        int mask = 0;
        for (char c : s)
            mask |= 1 << (c - '0');

        count[mask]++;
    }

    long long res = size * (size - 1LL) / 2;
    for (int a = 0; a < count.size(); a++)
        for (int b = a + 1; b < count.size(); b++)
            if (!(a & b))
                res -= 1LL * count[a] * count[b];

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