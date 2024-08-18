#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

bool solve() {
    vector<int> a;
    for (int value; cin >> value && value; ) {
        if (value == -1)
            return 0;
        a.push_back(value);
    }

    sort(a.begin(), a.end());

    int res = 0;
    for (int value : a)
        res += binary_search(a.begin(), a.end(), 2 * value);

    cout << res << "\n";
    return 1;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    while (solve());
}