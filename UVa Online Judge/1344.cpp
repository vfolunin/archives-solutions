#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

bool solve() {
    int n;
    cin >> n;

    if (!n)
        return 0;

    vector<int> a(n);
    for (int &x : a)
        cin >> x;
    sort(a.begin(), a.end());

    vector<int> b(n);
    for (int &x : b)
        cin >> x;
    sort(b.begin(), b.end());

    int res = 0;
    for (int al = 0, ar = n - 1, bl = 0, br = n - 1; al <= ar; ) {
        if (a[al] < b[bl]) {
            res -= 200;
            al++;
            br--;
        } else if (a[al] > b[bl]) {
            res += 200;
            al++;
            bl++;
        } else if (a[ar] > b[br]) {
            res += 200;
            ar--;
            br--;
        } else {
            if (a[al] < b[br])
                res -= 200;
            al++;
            br--;
        }
    }

    cout << res << "\n";
    return 1;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    while (solve());
}