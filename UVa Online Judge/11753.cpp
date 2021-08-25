#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

int rec(vector<int> &a, int l, int r, int add, int limit) {
    if (add > limit)
        return limit + 1;
    if (l >= r)
        return 0;
    if (a[l] == a[r])
        return rec(a, l + 1, r - 1, add, limit);
    return 1 + min(rec(a, l, r - 1, add + 1, limit), rec(a, l + 1, r, add + 1, limit));
}

void solve(int test) {
    int size, limit;
    cin >> size >> limit;

    vector<int> a(size);
    for (int &x : a)
        cin >> x;

    int res = rec(a, 0, size - 1, 0, limit);

    cout << "Case " << test << ": ";
    if (res == 0)
        cout << "Too easy\n";
    else if (res <= limit)
        cout << res << "\n";
    else
        cout << "Too difficult\n";
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int n;
    cin >> n;

    for (int test = 1; test <= n; test++)
        solve(test);
}