#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

void solve() {
    vector<int> count(4);
    for (int i = 0; i < 20; i++) {
        int value;
        cin >> value;

        count[value - 1]++;
    }

    vector<string> res = { "leader", "intellectual", "social", "practical" };
    cout << res[max_element(count.begin(), count.end()) - count.begin()] << "\n";
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int n;
    cin >> n;

    for (int i = 0; i < n; i++)
        solve();
}