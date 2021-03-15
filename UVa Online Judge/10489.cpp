#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

void solve() {
    int friendCount, boxCount;
    cin >> friendCount >> boxCount;

    int res = 0;

    for (int i = 0; i < boxCount; i++) {
        int levelCount;
        cin >> levelCount;

        int curRes = 1;
        for (int j = 0; j < levelCount; j++) {
            int x;
            cin >> x;
            curRes = curRes * x % friendCount;
        }

        res = (res + curRes) % friendCount;
    }

    cout << res << "\n";
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int n;
    cin >> n;

    for (int i = 0; i < n; i++)
        solve();
}