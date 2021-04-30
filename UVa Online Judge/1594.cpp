#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

void solve() {
    int n;
    cin >> n;

    vector<int> a(n);
    for (int &x : a)
        cin >> x;

    set<vector<int>> seen;
    while (*max_element(a.begin(), a.end()) && !seen.count(a)) {
        seen.insert(a);

        vector<int> nextA;
        for (int i = 0; i < a.size(); i++)
            nextA.push_back(abs(a[i] - a[(i + 1) % a.size()]));

        a = nextA;
    }

    cout << (seen.count(a) ? "LOOP\n" : "ZERO\n");
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int n;
    cin >> n;

    for (int i = 0; i < n; i++)
        solve();
}