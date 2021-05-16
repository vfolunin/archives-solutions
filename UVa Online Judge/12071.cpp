#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

bool solve(int test) {
    int n;
    cin >> n;

    if (!n)
        return 0;

    vector<int> a(n);
    for (int &x : a)
        cin >> x;
    sort(a.begin(), a.end());

    int res = 0;
    for (int i = 0, j = 0; i < n; i++) {
        while (j < n && a[i] == a[j])
            j++;
        res += n - j;
    }

    cout << "Case " << test << ": " << res << "\n";
    return 1;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    ios_base::sync_with_stdio(0);
    cin.tie(0);

    for (int test = 1; solve(test); test++);
}