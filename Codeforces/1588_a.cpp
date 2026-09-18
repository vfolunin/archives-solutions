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

    vector<int> a(size), b(size);
    for (int &value : a)
        cin >> value;
    sort(a.begin(), a.end());
    for (int &value : b)
        cin >> value;
    sort(b.begin(), b.end());

    int ok = 1;
    for (int i = 0; i < size; i++)
        ok &= a[i] == b[i] || a[i] + 1 == b[i];

    cout << (ok ? "YES\n" : "NO\n");
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
 
    int testCount;
    cin >> testCount;

    for (int test = 0; test < testCount; test++)
        solve();
}