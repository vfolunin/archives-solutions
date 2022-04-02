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

    vector<int> a(12);
    for (int &value : a)
        cin >> value;

    int islandCount = 0;
    for (int l = 1; l + 1 < a.size(); l++) {
        int minValue = a[l];
        for (int r = l; r + 1 < a.size(); r++) {
            minValue = min(minValue, a[r]);
            islandCount += a[l - 1] < minValue && minValue > a[r + 1];
        }
    }

    cout << test << " " << islandCount << "\n";
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int n;
    cin >> n;

    for (int i = 0; i < n; i++)
        solve();
}