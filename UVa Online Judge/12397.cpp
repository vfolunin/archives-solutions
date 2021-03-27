#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

bool solve() {
    int n;
    if (!(cin >> n))
        return 0;

    static vector<int> matches = { 1, 3, 2, 3, 2, 4, 2, 4, 2, 5, 3, 6, 4 };
    static vector<int> vals = { 1, 4, 5, 9, 10, 40, 50, 90, 100, 400, 500, 900, 1000 };

    int res = 0;
    for (int i = vals.size() - 1; i >= 0; i--) {
        res += n / vals[i] * matches[i];
        n %= vals[i];
    }

    cout << res << "\n";
    return 1;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    while (solve());
}