#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

void solve() {
    int value;
    cin >> value;

    static vector<int> limit = { (int)-2e9, 1000, 1200, 1500, 1800, 2200, 3000, 4000};
    static vector<string> name = { "Newbie", "Amateur", "Expert", "Candidate Master", "Master", "Grandmaster", "Target", "Rainbow Master" };

    cout << name[upper_bound(limit.begin(), limit.end(), value) - limit.begin() - 1] << "\n";
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int n;
    cin >> n;

    for (int i = 0; i < n; i++)
        solve();
}