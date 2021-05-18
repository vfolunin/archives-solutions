#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

bool solve() {
    string s;
    if (!(cin >> s))
        return 0;

    long long res = 0;
    int sum = 0;
    vector<int> seen = { 1, 0, 0 };

    for (char c : s) {
        if (isdigit(c)) {
            sum = (sum + c - '0') % 3;
            res += seen[sum];
            seen[sum]++;
        } else {
            sum = 0;
            seen = { 1, 0, 0 };
        }
    }

    cout << res << "\n";
    return 1;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    while (solve());
}