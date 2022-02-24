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

    vector<int> heights;
    int stepCount = 0;

    for (int i = 0; i < 20; i++) {
        int height;
        cin >> height;

        auto it = upper_bound(heights.begin(), heights.end(), height);
        stepCount += heights.end() - it;
        heights.insert(it, height);
    }

    cout << test << " " << stepCount << "\n";
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int n;
    cin >> n;

    for (int i = 0; i < n; i++)
        solve();
}