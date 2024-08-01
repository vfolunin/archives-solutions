#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
#include <numeric>
using namespace std;

void solve() {
    vector<int> a;
    do {
        int value;
        cin >> value;
        a.push_back(value);
    } while (cin.peek() == ' ');

    int res = 0;
    for (int i = 0; i < a.size(); i++)
        for (int j = i + 1; j < a.size(); j++)
            res = max(res, gcd(a[i], a[j]));

    cout << res << "\n";
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int n;
    cin >> n;

    for (int i = 0; i < n; i++)
        solve();
}