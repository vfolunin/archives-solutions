#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int n;
    cin >> n;

    vector<int> seen(n);
    for (int i = 0; i < n; i++) {
        int l, r;
        cin >> l >> r;

        if (l >= 0 && r >= 0 && l + 1 + r == n)
            seen[l] = 1;
    }

    cout << count(seen.begin(), seen.end(), 1);
}