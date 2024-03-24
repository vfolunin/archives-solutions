#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

void solve() {
    int test;
    cin >> test;

    vector<int> a(10);
    for (int &value : a)
        cin >> value;

    sort(a.begin(), a.end());

    cout << test << " " << a[7] << "\n";
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int n;
    cin >> n;

    for (int i = 0; i < n; i++)
        solve();
}