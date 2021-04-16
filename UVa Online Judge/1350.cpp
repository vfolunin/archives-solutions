#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

vector<vector<int>> getCount() {
    vector<vector<int>> count = { { 1, 1 }, { 1, 1 } };
    for (int i = 2; count[1].back() <= 1e8; i++) {
        count[0].push_back(count[0][i - 1] + count[1][i - 1]);
        count[1].push_back(count[0][i - 1]);
    }
    return count;
}

void solve() {
    int n;
    cin >> n;
    n--;

    static vector<vector<int>> count = getCount();

    int len = 1;
    while (n >= count[1][len]) {
        n -= count[1][len];
        len++;
    }

    cout << 1;
    for (int i = 1; i < len; i++) {
        if (n < count[0][len - i]) {
            cout << 0;
        } else {
            cout << 1;
            n -= count[0][len - i];
        }
    }
    cout << "\n";
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int n;
    cin >> n;

    for (int i = 0; i < n; i++)
        solve();
}