#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

void solve() {
    string a;
    cin >> a >> a;

    string b = a;
    sort(b.begin(), b.end());

    int diff = 0;
    for (int i = 0; i < a.size(); i++)
        diff += a[i] != b[i];

    cout << "There are" << (diff == 2 ? "" : "n't") << " the chance.\n";
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int n;
    cin >> n;

    for (int i = 0; i < n; i++)
        solve();
}