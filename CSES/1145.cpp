#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int n;
    cin >> n;

    vector<int> last(n + 1, 2e9);
    last[0] = -2e9;

    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        *lower_bound(last.begin(), last.end(), x) = x;
    }

    int res = n;
    while (last[res] == 2e9)
        res--;

    cout << res;
}