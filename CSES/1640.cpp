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

    int n, targetSum;
    cin >> n >> targetSum;

    vector<pair<long long, int>> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i].first;
        a[i].second = i;
    }

    sort(a.begin(), a.end());

    for (int l = 0, r = n - 1; l < r; l++) {
        while (l < r && a[l].first + a[r].first > targetSum)
            r--;
        if (l < r && a[l].first + a[r].first == targetSum) {
            cout << a[l].second + 1 << " " << a[r].second + 1 << "\n";
            return 0;
        }
    }

    cout << "IMPOSSIBLE";
}