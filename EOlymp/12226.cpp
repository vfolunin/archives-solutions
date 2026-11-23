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

    vector<int> l(size);
    for (int &value : l)
        cin >> value;

    vector<int> r(size);
    for (int &value : r)
        cin >> value;
    reverse(r.begin(), r.end());

    vector<int> a = l;
    for (int i = 1; i < a.size(); i++)
        a[i] -= l[i - 1];

    long long sum = 0;
    bool ok = 1;
    for (int i = a.size() - 1; i >= 0; i--) {
        sum += a[i];
        ok &= sum == r[i];
    }

    if (ok) {
        for (int value : a)
            cout << value << " ";
        cout << "\n";
    } else {
        cout << "-1\n";
    }
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int testCount;
    cin >> testCount;

    for (int test = 0; test < testCount; test++)
        solve();
}