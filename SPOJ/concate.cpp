#include <iostream>
#include <algorithm>
#include <vector>
#include <unordered_set>
#include <map>
#include <string>
using namespace std;

void solve() {
    string s;
    int divisor;
    cin >> s >> divisor;

    int remainder = 0;
    for (char c : s)
        remainder = (remainder * 10 + c - '0') % divisor;

    unordered_set<int> seen;
    for (int i = 1; 1; i++) {
        if (!remainder) {
            cout << i << "\n";
            return;
        }
        if (seen.count(remainder)) {
            cout << "-1\n";
            return;
        }
        seen.insert(remainder);
        for (char c : s)
            remainder = (remainder * 10 + c - '0') % divisor;
    }
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int n;
    cin >> n;

    for (int i = 0; i < n; i++)
        solve();
}