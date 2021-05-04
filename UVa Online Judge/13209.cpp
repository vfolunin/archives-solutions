#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

void solve() {
    int den;
    cin >> den;

    vector<int> seen(den);
    seen[0] = 1;

    int num = 1;
    cout << "0.";

    while (!seen[num]) {
        seen[num] = 1;
        cout << num * 10 / den;
        num = num * 10 % den;
    }
    cout << "\n";
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int n;
    cin >> n;

    for (int i = 0; i < n; i++)
        solve();
}