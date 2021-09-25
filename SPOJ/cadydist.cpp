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

    vector<int> a(size);
    for (int &x : a)
        cin >> x;
    sort(a.begin(), a.end());

    vector<int> b(size);
    for (int &x : b)
        cin >> x;
    sort(b.rbegin(), b.rend());

    long long res = 0;
    for (int i = 0; i < size; i++)
        res += 1LL * a[i] * b[i];

    cout << res << "\n";
    return 1;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    while (solve());
}