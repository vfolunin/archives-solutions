#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int n;
    cin >> n;

    vector<vector<int>> a(2);
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        a[x % 2].push_back(x);
    }

    sort(a[0].begin(), a[0].end());
    for (int x : a[0])
        cout << x << "\n";

    sort(a[1].rbegin(), a[1].rend());
    for (int x : a[1])
        cout << x << "\n";
}