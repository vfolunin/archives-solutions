#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
#include <numeric>
using namespace std;

void solve() {
    int size;
    cin >> size;

    vector<int> a(size);
    iota(a.begin(), a.end(), 0);

    for (int step = 1, pos = 0; a.size() > 1; step++) {
        pos = (pos + step - 1) % a.size();
        a.erase(a.begin() + pos);
        pos %= a.size();
    }

    cout << a[0] + 1 << "\n";
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int n;
    cin >> n;

    for (int i = 0; i < n; i++)
        solve();
}