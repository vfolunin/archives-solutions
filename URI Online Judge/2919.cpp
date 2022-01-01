#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

bool solve() {
    int size;
    if (!(cin >> size))
        return 0;

    vector<int> last(size + 1, 2e9);
    last[0] = -2e9;

    for (int i = 0; i < size; i++) {
        int x;
        cin >> x;
        *lower_bound(last.begin(), last.end(), x) = x;
    }

    int res = size;
    while (last[res] == 2e9)
        res--;

    cout << res << "\n";
    return 1;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    while (solve());
}