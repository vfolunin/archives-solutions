#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

bool solve() {
    int size;
    cin >> size;

    if (!size)
        return 0;

    vector<long long> a(size);
    for (long long &x : a)
        cin >> x;

    long long res = 0, add = 0;
    for (int i = size - 1; i >= 0; i--) {
        res += a[i] + add;
        add += a[i] + add;
    }

    cout << res << "\n";
    return 1;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    while (solve());
}