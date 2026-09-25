#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

void solve() {
    int size, price;
    cin >> size >> price;

    vector<int> a(size);
    for (int &value : a)
        cin >> value;

    vector<int> b(size);
    for (int &value : b)
        cin >> value;

    int res = 0;
    for (int i = 0; i < a.size(); i++) {
        if (a[i] < b[i]) {
            res += price;
            break;
        }
    }

    sort(a.begin(), a.end());
    sort(b.begin(), b.end());

    for (int i = 0; i < a.size(); i++) {
        if (a[i] < b[i]) {
            cout << "-1\n";
            return;
        }
        res += a[i] - b[i];
    }

    cout << res << "\n";
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int testCount;
    cin >> testCount;

    for (int test = 0; test < testCount; test++)
        solve();
}