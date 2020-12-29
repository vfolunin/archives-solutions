#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

bool solve() {
    int n;
    if (!(cin >> n))
        return 0;

    vector<int> a(n);
    for (int &x : a)
        cin >> x;

    int res = 0;
    for (int i = 0; i < n; i++)
        for (int j = i + 1; j < n; j++)
            res += a[i] > a[j];

    cout << "Minimum exchange operations : " << res << "\n";
    return 1;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    while (solve());
}